class User {
  final String avatarUrl;
  final String nick;
  final String openId;
  final String openSid;

  User({this.avatarUrl, this.nick, this.openId, this.openSid});
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

