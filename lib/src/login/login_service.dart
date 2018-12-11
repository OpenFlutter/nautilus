class User {
  final String avatarUrl;
  final String nick;
  final String openId;
  final String openSid;
  final String topAccessToken;
  final String topAuthCode;


  User({this.avatarUrl, this.nick, this.openId, this.openSid,this.topAccessToken,this.topAuthCode});
}

class LoginResult {
  final String platform;
  final bool result;
  final int errorCode;
  final String errorMessage;
  final User user;

  LoginResult(
      {this.platform,
      this.result,
      this.errorCode,
      this.errorMessage,
      this.user});
}

