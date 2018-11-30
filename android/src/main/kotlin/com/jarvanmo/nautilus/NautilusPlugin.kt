package com.jarvanmo.nautilus

import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import io.flutter.plugin.common.PluginRegistry.Registrar

class NautilusPlugin(registrar: Registrar) : MethodCallHandler {

    private val nautilusLoginService = LoginServiceHandler(registrar)
    private val tradeHandler = TradeHandler(registry = registrar)

    companion object {
        @JvmStatic
        fun registerWith(registrar: Registrar) {
            val channel = MethodChannel(registrar.messenger(), "com.jarvanmo/nautilus")
            channel.setMethodCallHandler(NautilusPlugin(registrar))
        }
    }

    override fun onMethodCall(call: MethodCall, result: Result) {
        when {
            "login" == call.method -> nautilusLoginService.handleLogin(call, result)
            "initLogin" == call.method -> nautilusLoginService.initLogin(result)
            "isLogin" == call.method -> nautilusLoginService.handleIsLogin(result)
            "getUser" == call.method -> nautilusLoginService.handleGetUser(result)
            "logout" == call.method -> nautilusLoginService.handleLogout(result)
            "initTradeAsync" == call.method -> tradeHandler.initTradeAsync(call,result)
            "openItemDetail" == call.method -> tradeHandler.openItemDetail(call,result)
            "openUrl" == call.method -> tradeHandler.openUrl(call, result)
            "destroy" == call.method -> tradeHandler.destroy()
            else -> result.notImplemented()
        }
    }


}
