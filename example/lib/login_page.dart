import 'package:flutter/material.dart';
import 'package:nautilus/nautilus.dart' as nautilus ;

class LoginPage extends StatefulWidget {
  @override
  _LoginPageState createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {

  String _result ="";
  String _initResult = "未初始化";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Login With Taobao"),),
      body: Column(
        children: <Widget>[
          FlatButton(onPressed: (){
            nautilus.login().then((data){
              setState(() {
                _result ="nick->${data.user.nick}";
              });
            });
          }, child: Text("Login with TaoBao")),
          Text(_result)
        ],
      ),
    );
  }
}
