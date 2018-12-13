import 'package:flutter/material.dart';
import 'open_page.dart';
import 'login_page.dart';
import 'package:nautilus/nautilus.dart' as nautilus;
void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {

  @override
  void initState() {
    super.initState();
  }



  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      routes:<String, WidgetBuilder>{
        "Login":(context)=> LoginPage(),
        "OpenPage":(context)=>OpenByPage()
      },
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body:HomeBody()
      ),
    );
  }
}

class HomeBody extends StatefulWidget {
  @override
  HomeBodyState createState() {
    return new HomeBodyState();
  }
}

class HomeBodyState extends State<HomeBody> {

  String _initTradeServiceResult="初始化结果：";
  @override
  void initState() {
    super.initState();
    initTradeService();
  }

  void initTradeService(){
    nautilus.initTradeAsync(debuggable: false).then((data){
      setState(() {
        _initTradeServiceResult ="初始化结果：${data.isSuccessful}";
      });
    });
  }
  @override
  Widget build(BuildContext context) {
    return  ListView(
      children: <Widget>[
        Padding(
          padding: const EdgeInsets.all(8.0),
          child: new Text(_initTradeServiceResult)),
        Padding(
          padding: const EdgeInsets.all(8.0),
          child: new OutlineButton(
              onPressed: () {
                Navigator.of(context).pushNamed("Login");
              },
              child: const Text("Login with Taobao")),
        ),
        Padding(
          padding: const EdgeInsets.all(8.0),
          child: new OutlineButton(
              onPressed: () {
                Navigator.of(context).pushNamed("OpenPage");
              },
              child: const Text("Open Page")),
        )
      ],
    );
  }
}

