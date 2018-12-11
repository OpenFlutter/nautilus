# Nautilus ![pub package](https://img.shields.io/pub/v/nautilus.svg)

![logo](./arts/logo.png)

Nautilus是阿里百川电商SDK在Flutter上的实现，通过Nautilus可以实现淘宝登录，打开淘宝商品详情等功能。

> Nautilus原本是在一位热心网友的赞助下开发的，现应该网友要求将其开源。在此特别感谢这位朋友。
> 欢迎加入QQ群：892398530共同交流。

## 使用需知
同样地，我建议去下载下百川电商SDK Demo并阅读相关文档，并参考官网文档，尽管官网的文档很坑。因为很多内容我不会在这里做赘述。
也欢迎各位朋友PR。

## 初始化
```dart
 import 'package:nautilus/nautilus.dart' as nautilus;
 InitAsyncResult  result = await nautilus.initTradeAsync();
```
## 淘宝授权登录
进行登录:
```dart
InitAsyncResult result = await nautilus.login();
```
我们也可以通过*nautilus*获取当用户信息：
```dart
 import 'package:nautilus/nautilus.dart' as nautilus;
 User user = await nautilus.getUser();
```
也可以查询当前用户是否登录：
```dart
 import 'package:nautilus/nautilus.dart' as nautilus;
 bool isLogin = await nautilus.isLogin();
```

## 打开淘宝详情：
```dart 
 import 'package:nautilus/nautilus.dart' as nautilus;
 nautilus.openItemDetail(itemID: "41576306115");
```

## 打开淘宝URL
```dart 
 import 'package:nautilus/nautilus.dart' as nautilus;
 nautilus.openUrl(pageUrl: "https://taoquan.taobao.com/coupon/unify_apply.htm?sellerId=2165762428&activityId=5698d91c0b474d9caf88279009bda4f3");
```
## 更多功能敬请期待

### 捐助
请作者喝杯咖啡。

<img src="./arts/wx.jpeg" height="300">  <img src="./arts/ali.jpeg" height="300">

## LICENSE


    Copyright 2018 OpenFlutter Project

    Licensed to the Apache Software Foundation (ASF) under one or more contributor
    license agreements.  See the NOTICE file distributed with this work for
    additional information regarding copyright ownership.  The ASF licenses this
    file to you under the Apache License, Version 2.0 (the "License"); you may not
    use this file except in compliance with the License.  You may obtain a copy of
    the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
    WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
    License for the specific language governing permissions and limitations under
    the License.
