package com.gluedtomatoes.artrix;

import android.app.Activity;
import android.graphics.Point;
import android.view.Display;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Transform {
    public static int mScreenWidthPixels;
    public static int mScreenHeightPixels;
    public static int mHalfscreenWidthPixels;
    public static int mHalfScreenHeightPixels;
    public static float mAspectRatio;

    public static void init(Activity activity){
        /** intiialize the constants that will be used throught **/
        Display display  = activity.getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);

        mScreenWidthPixels = size.x;
        mScreenHeightPixels = size.y;

        mHalfscreenWidthPixels = mScreenWidthPixels / 2;
        mHalfScreenHeightPixels = mScreenHeightPixels / 2;

        if(mScreenWidthPixels > mScreenHeightPixels)
            mAspectRatio = mScreenWidthPixels/(mScreenHeightPixels * 1.0f);
        else
            mAspectRatio = mScreenHeightPixels /(mScreenWidthPixels * 1.0f);

    }

    public static void ScreenToWorld(){

    }
    public static void WorldToScreen(){

    }
    public static Point CoordsToPixels(Vector3 vector){
        Point screen = new Point();
        screen.x = (int)vector.mX * mScreenWidthPixels;
        screen.y = (int)vector.mY * mScreenHeightPixels;
        return screen;
    }

    /***
     * converts from pixels to cooridnates
     */
    public static Vector3 PixelsToCoords(Point point){
        Vector3 coords = new Vector3();
        coords.mX = point.x / mScreenWidthPixels;
        coords.mY = point.y / mScreenHeightPixels;
        return  coords;
    }

    private Transform mParent;

    private Matrix4x4 mLocal;
    public Matrix4x4 getLocal() {
        return mLocal;
    }

    public Matrix4x4 getWorld() {
        if(mParent != null){
            return mParent.getWorld().multiply(mLocal);
        }
        return mLocal;
    }
}
