import 'package:flutter/material.dart';
import 'package:nautilus/nautilus.dart'as nautilus;
class OpenByPage extends StatefulWidget  {
  @override
  _OpenByPageState createState() => _OpenByPageState();
}

class _OpenByPageState extends State<OpenByPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("OpenByPage"),
      ),
      body: ListView(
        children: <Widget>[
          FlatButton(onPressed: _openItemDetail,
          child: Text("打开淘宝详情"),
          ),
          FlatButton(onPressed: _openUrl,
          child: Text("打开Url"),
          )
        ],
      ),
    );
  }

  _openItemDetail(){
    nautilus.openItemDetail(itemID: "41576306115");
  }
  _openUrl(){
    nautilus.openUrl(pageUrl: "https://taoquan.taobao.com/coupon/unify_apply.htm?sellerId=2165762428&activityId=5698d91c0b474d9caf88279009bda4f3");
  }
}
