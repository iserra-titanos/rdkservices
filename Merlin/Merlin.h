#pragma once

#include "Module.h"

namespace WPEFramework
{
namespace Plugin
{
class Merlin : public PluginHost::IPlugin, public PluginHost::JSONRPC
{
    private:
        Merlin(const Merlin &) = delete;
        Merlin &operator=(const Merlin &) = delete;

//        /** Future Features **/
//        class Notification : public PluginHost::IStateControl::INotification {
//            private:
//                Notification() = delete;
//                Notification(const Notification&) = delete;
//                Notification& operator=(const Notification&) = delete;
//
//            public:
//                explicit Notification(Merlin* parent)
//                    : _parent(*parent)
//                {
//                    ASSERT(parent != nullptr);
//                }
//                ~Notification() override
//                {}
//
//            public:
//                void VisibilityChange(const bool hidden) override
//                {
//                    _parent.VisibilityChange(hidden);
//                }
//                void StateChange(const PluginHost::IStateControl::state state) override
//                {
//                    _parent.StateChange(state);
//                }
//
//                BEGIN_INTERFACE_MAP(Notification)
//                INTERFACE_ENTRY(PluginHost::IStateControl::INotification)
//                END_INTERFACE_MAP
//
//            private:
//                Merlin& _parent;
//        };

//    public: /** Future Features **/
//        class Data : public Core::JSON::Container {
//        private:
//            Data(const Data&) = delete;
//            Data& operator=(const Data&) = delete;
//
//        public:
//            Data()
//                : Core::JSON::Container()
//                , Suspended(false)
//                , Hidden(false)
//                , DemoMode(true)
//            {
//                Add(_T("suspended"), &Suspended);
//                Add(_T("hidden"), &Hidden);
//                Add(_T("demo"), &DemoMode);
//            }
//            ~Data()
//            {}
//
//        public:
//            Core::JSON::Boolean Suspended;
//            Core::JSON::Boolean Hidden;
//            Core::JSON::Boolean DemoMode;
//        //            Core::JSON::DecUInt32 FPS;
//        };

    public:
        Merlin();
        virtual ~Merlin();

        // Build QueryInterface implementation, specifying all possible interfaces to be returned.
        BEGIN_INTERFACE_MAP(Merlin)
        INTERFACE_ENTRY(PluginHost::IPlugin)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
        END_INTERFACE_MAP

    public:
        //   IPlugin methods
        // -------------------------------------------------------------------------------------------------------
        virtual const string Initialize(PluginHost::IShell *service) override;
        virtual void Deinitialize(PluginHost::IShell *service) override;
        virtual string Information() const override;

    protected:
        void RegisterAll();
        void UnregisterAll();

//        uint32_t get_state(Core::JSON::EnumType<JsonData::StateControl::StateType>& response) const; // StateControl
//        uint32_t set_state(const Core::JSON::EnumType<JsonData::StateControl::StateType>& param); // StateControl

//        void event_onStateChanged(const string &state);
//        void event_onVisibilityChanged(const string &key, const string &value);
};

} // namespace Plugin
} // namespace WPEFramework
