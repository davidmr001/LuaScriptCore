//
// Created by 冯鸿杰 on 16/9/23.
//

#ifndef ANDROID_LUAMODULE_H
#define ANDROID_LUAMODULE_H

#include "LuaObject.h"
#include "lua.hpp"
#include "LuaContext.h"
#import "LuaDefined.h"
#include "../../../../../lua-core/src/lua.h"

namespace cn
{
    namespace vimfung
    {
        namespace luascriptcore
        {
            class LuaContext;

            /**
             * Lua模块对象,用于描述Lua中的一个模块
             */
            class LuaModule : public LuaObject
            {
            protected:

                /**
                 * 模块名称
                 * **/
                std::string _name;

                /**
                 * 上下文对象
                 */
                LuaContext *_context;

                /**
                 * 方法表
                 */
                LuaModuleMethodMap _methodMap;

            public:

                /**
                 * 模块被注册时触发,该方法仅被LuaContext调用
                 *
                 * @param name 模块名称
                 * @param context 上下文对象
                 */
                 virtual void onRegister (const std::string &name, LuaContext *context);

            public:

                /**
                 * 获取Lua上下文对象, 提供Lua回调方法调用
                 *
                 * @return 上下文对象
                 */
                LuaContext* getContext();

                /**
                 * 获取模块名称,提供Lua回调方法调用
                 *
                 * @return 模块名称
                 */
                const std::string getName();

                /**
                 * 获取模块方法处理器, 提供Lua回调方法调用
                 *
                 * @param methodName 方法名称
                 *
                 * @return 模块方法处理器
                 */
                LuaModuleMethodHandler getMethodHandler(std::string methodName);

            public:

                /**
                 * 注册方法
                 *
                 * @param methodName 方法名称
                 * @param handler 方法处理器
                 */
                void registerMethod(std::string methodName, LuaModuleMethodHandler handler);
            };
        }
    }
}

#endif //ANDROID_LUAMODULE_H
