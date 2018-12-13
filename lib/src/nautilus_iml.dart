import 'dart:async';

import 'package:flutter/services.dart';
import 'login/login_service.dart';
import 'trade/trade_sdk.dart';
import 'package:flutter/foundation.dart';

final MethodChannel _channel = const MethodChannel('com.jarvanmo/nautilus');

const _keyPlatform = "platform";
const _keyResult = "result";
const _keyErrorCode = "errorCode";
const _keyErrorMessage = "errorMessage";



Future<LoginResult> login() async {
  Map result = await _channel.invokeMethod("login");
  bool isSuccess = result[_keyResult];

  LoginResult loginResult;
  if (isSuccess) {
    Map userMap = result["user"];
    User user = User(
        avatarUrl: userMap["avatarUrl"],
        nick: userMap["nick"],
        openId: userMap["openId"],
        openSid: userMap["openSid"],
        topAccessToken:userMap["topAccessToken"],
        topAuthCode:userMap["topAuthCode"]
        );
    loginResult = LoginResult(
        isSuccessful: isSuccess,
        platform: result[_keyPlatform],
        errorCode: null,
        errorMessage: null,
        user: user);
  } else {
    loginResult = LoginResult(
        isSuccessful: isSuccess,
        platform: result[_keyPlatform],
        errorCode: result[_keyErrorCode],
        errorMessage: result[_keyErrorMessage],
        user: null);
  }

  return loginResult;
}

Future<bool> isLogin() async {
  return await _channel.invokeMethod("isLogin");
}

Future<User> getUser() async {
  Map result = await _channel.invokeMethod("getUser");
  User user;
  bool isSuccess = result[_keyResult];

  if (isSuccess) {
    Map userMap = result["user"];
    user = User(
        avatarUrl: userMap["avatarUrl"],
        nick: userMap["nick"],
        openId: userMap["openId"],
        openSid: userMap["openSid"],
        topAccessToken:userMap["topAccessToken"],
        topAuthCode:userMap["topAuthCode"]);
  }

  return user;
}

///
/// {
///    "platform":"iOS",
///    "result":true
///  };
Future<Map> logout() async {
  return await _channel.invokeMethod("logout");
}

Future<InitAsyncResult> initTradeAsync(
    {bool debuggable = false, String version}) async {
  Map result = await _channel.invokeMethod(
      "initTradeAsync", {"debuggable": debuggable, "version": version});
  assert(debuggable != null);
  return InitAsyncResult(
      platform: result[_keyPlatform],
      isSuccessful: result[_keyResult],
      errorMessage: result[_keyErrorMessage],
      errorCode: result[_keyErrorCode]);
}


///[needPush] only works on iOS
///[schemeType] supports 'tmall_scheme' and 'taobao_scheme','tmall_scheme' as default
///By passing a non-null [taoKeParams],we mean it's a TaoKe.
Future<TradeResult> openItemDetail({@required String itemID,
  String backUrl="",
  Map<String, String> extParams,
  TaoKeParams taoKeParams,
  bool needPush = false,
  String schemeType = "tmall_scheme",
  OpenType openType = OpenType.AUTO,
  OpenNativeFailedMode openNativeFailedMode =
      OpenNativeFailedMode.JUMP_H5}) async {
  assert(needPush != null ||
      openType != null ||
      openNativeFailedMode != null);


  Map taoKe;
  if (taoKeParams != null) {
    taoKe = {
      "taoKeParamsPid": taoKeParams.pid,
      "taoKeParamsSubPid": taoKeParams.subPid,
      "taoKeParamsUnionId": taoKeParams.unionId,
      "taoKeParamsAdzoneId": taoKeParams.adzoneId,
      "taoKeParamsExtParams": taoKeParams.extParams
    };
  }


  Map des = {
    "itemID": itemID,
    "backUrl": backUrl==null?"":backUrl,
    "extParams": extParams,
    "needPush": needPush,
    "openType": openType.index,
    "schemeType": schemeType,
    "openNativeFailedMode": openNativeFailedMode.index,
    "taoKeParams":taoKe
  };


  Map result = await _channel.invokeMethod("openItemDetail", des);

  TradeResultType tradeResultType = result["tradeResultType"] == 0
      ? TradeResultType.PaySuccess
      : TradeResultType.AddCard;
  return TradeResult(
      openResultCode: result["openResultCode"],
      platform: result[_keyPlatform],
      isSuccessful: result["result"],
      tradeResultType: tradeResultType,
      paySuccessOrders: result["paySuccessOrders"],
      payFailedOrders: result["payFailedOrders"],
      errorCode: result[_keyErrorCode],
      errorMessage: result[_keyErrorMessage]);
}


///[needPush] only works on iOS
///[schemeType] supports 'tmall_scheme' and 'taobao_scheme','tmall_scheme' as default
///By passing a non-null [taoKeParams],we mean it's a TaoKe.
Future<TradeResult> openUrl({@required String pageUrl,
  String backUrl="",
  Map<String, String> extParams,
  TaoKeParams taoKeParams,
  bool needPush = false,
  String schemeType = "tmall_scheme",
  OpenType openType = OpenType.AUTO,
  OpenNativeFailedMode openNativeFailedMode =
      OpenNativeFailedMode.JUMP_H5}) async {
  assert(needPush != null ||
      openType != null ||
      openNativeFailedMode != null);


  Map taoKe;
  if (taoKeParams != null) {
    taoKe = {
      "taoKeParamsPid": taoKeParams.pid,
      "taoKeParamsSubPid": taoKeParams.subPid,
      "taoKeParamsUnionId": taoKeParams.unionId,
      "taoKeParamsAdzoneId": taoKeParams.adzoneId,
      "taoKeParamsExtParams": taoKeParams.extParams
    };
  }

  Map des = {
    "pageUrl": pageUrl,
    "backUrl": backUrl==null?"":backUrl,
    "extParams": extParams,
    "needPush": needPush,
    "openType": openType.index,
    "schemeType": schemeType,
    "taoKeParams":taoKe,
    "openNativeFailedMode": openNativeFailedMode.index
  };


  Map result = await _channel.invokeMethod("openUrl", des);

  TradeResultType tradeResultType = result["tradeResultType"] == 0
      ? TradeResultType.PaySuccess
      : TradeResultType.AddCard;
  return TradeResult(
      openResultCode: result["openResultCode"],
      platform: result[_keyPlatform],
      isSuccessful: result["result"],
      tradeResultType: tradeResultType,
      paySuccessOrders: result["paySuccessOrders"],
      payFailedOrders: result["payFailedOrders"],
      errorCode: result[_keyErrorCode],
      errorMessage: result[_keyErrorMessage]);
}
