#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H
#include <android/log.h>
#include <string>
#include <vector>
#include <tinyxml2.h>
#include "agk.h"
#include "screen.h"
#include "WidgetFactory.h"
#include "ButtonWidget.h"
#include "Managers.h"
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))

using namespace std;
using namespace AGK;
using namespace tinyxml2;
class ConfigurationManager
{
    public:
        ConfigurationManager();
        virtual ~ConfigurationManager();
        static ConfigurationManager* GetInstance();
        static void DestroyInstance();

        void GenerateFactoryConfiguration();
        void ParseScreens(const string& file);
        void ParseConfig(const string& file);
        vector<Screen*> GetScreens();
    protected:
    private:
        static ConfigurationManager* mInstance;
        vector<Screen*> mScreens;
        const void ReadFromAGKFile(const string& file, XMLDocument*);
};

#endif // CONFIGURATIONMANAGER_H
