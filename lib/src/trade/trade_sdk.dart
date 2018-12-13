import 'package:flutter/foundation.dart';

class InitAsyncResult {
  final String platform;
  final bool isSuccessful;
  final int errorCode;
  final String errorMessage;

  InitAsyncResult(
      {this.platform, this.isSuccessful, this.errorCode, this.errorMessage});
}

class TaoKeParams {
  final String pid;
  final String subPid;
  final String unionId;
  final String adzoneId;
  final Map<String, String> extParams;

  TaoKeParams(
      {@required this.pid,
      @required this.subPid,
      @required this.unionId,
      @required this.adzoneId,
      this.extParams});
}

class TradeResult {
  final int openResultCode;
  final String platform;
  final bool isSuccessful;
  final int errorCode;
  final String errorMessage;
  final TradeResultType tradeResultType;
  final List<String> paySuccessOrders;
  final List<String> payFailedOrders;

  TradeResult(
      {this.openResultCode,
      this.platform,
      this.isSuccessful,
      this.errorCode,
      this.errorMessage,
      this.tradeResultType,
      this.paySuccessOrders,
      this.payFailedOrders});
}

enum OpenType { AUTO, NATIVE, H5 }

enum OpenNativeFailedMode { JUMP_H5, JUMP_DOWNLOAD, JUMP_BROWSER, NONE }

enum TradeResultType { PaySuccess, AddCard }
