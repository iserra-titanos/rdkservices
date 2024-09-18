#include "Merlin.h"
    
#define API_VERSION_NUMBER_MAJOR 1
#define API_VERSION_NUMBER_MINOR 0
#define API_VERSION_NUMBER_PATCH 0

namespace WPEFramework {

namespace {

    static Plugin::Metadata<Plugin::Merlin> metadata(
        // Version (Major, Minor, Patch)
        API_VERSION_NUMBER_MAJOR, API_VERSION_NUMBER_MINOR, API_VERSION_NUMBER_PATCH,
        // Preconditions
        {},
        // Terminations
        {},
        // Controls
        {}
    );
}

namespace Plugin {

SERVICE_REGISTRATION(Merlin, API_VERSION_NUMBER_MAJOR, API_VERSION_NUMBER_MINOR, API_VERSION_NUMBER_PATCH);

Merlin::Merlin()
    : PluginHost::JSONRPC(),
{
    RegisterAll();
}

Merlin::~Merlin()
{
    UnregisterAll();
}

const string Merlin::Initialize(PluginHost::IShell *service)
{
    string result;

    ASSERT(service != nullptr);

    string configLine = service->ConfigLine();
    TRACE(Trace::Information, (string(_T("Initialize: " + configLine))));

      
    // if there is error in initialization, return useful error information in result
    return result;
/*
    string configLine = service->ConfigLine();
    _config.FromString(configLine);

    ASSERT(!_config.Path.Value().empty());

    Core::File file(_config.Path.Value());

    Core::Directory(file.PathName().c_str()).CreatePath();

    if (!file.Exists()) {
        for (auto i : LegacyLocations()) {
            Core::File from(i);

            if (from.Exists()) {
                if (!Utils::MoveFile(from.Name(), file.Name())) {
                    result = "move failed";
                }
                break;
            }
        }
    }

    if (result.empty()) {
        if (static_cast<SqliteStore *>(_store)->Open(
            _config.Path.Value(),
            _config.Key.Value(),
            _config.MaxSize.Value(),
            _config.MaxValue.Value()) != Core::ERROR_NONE) {
            result = "init failed";
        }
    }

    if (result.empty()) {
        _storeSink.Initialize(_store);
    }
*/
    return result;
}

void Merlin::Deinitialize(PluginHost::IShell * /* service */)
{

}

string Merlin::Information() const
{
    // No additional info to report.
    return {};
}

void Merlin::RegisterAll()
{
//    Register<JsonObject, JsonObject>(_T("setValue"), &Merlin::endpoint_setValue, this);
}

void Merlin::UnregisterAll()
{
//    Unregister(_T("setValue"));
}
/*
uint32_t Merlin::endpoint_setValue(const JsonObject &parameters, JsonObject &response)
{
    LOGINFOMETHOD();

    bool success = false;

    if (!parameters.HasLabel("key") ||
        !parameters.HasLabel("value")) {
        response["error"] = "params missing";
    }
    else {
        string key = parameters["key"].String();
        string value = parameters["value"].String();

        if (key.empty()) {
            response["error"] = "params empty";
        }
        else {
            auto status = _store->SetValue(key, value);
            if (status == Core::ERROR_INVALID_INPUT_LENGTH) {
                response["error"] = "params too long";
            }
            success = (status == Core::ERROR_NONE);
        }
    }

    returnResponse(success);
}

void Merlin::event_onValueChanged(const string &key, const string &value)
{
    JsonObject params;
    params["key"] = key;
    params["value"] = value;

    sendNotify(_T("onValueChanged"), params);
}
*/

} // namespace Plugin
} // namespace WPEFramework
