#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#
Pod::Spec.new do |s|
  s.name             = 'nautilus'
  s.version          = '0.0.1'
  s.summary          = 'A plugin for BaiChuanSDK.'
  s.description      = <<-DESC
A plugin for BaiChuanSDK.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/Headers/**/*.h'
  s.dependency 'Flutter'

  s.vendored_frameworks ="Frameworks/*.framework"
  s.resource = "Resources/*.bundle"

  s.frameworks = "MobileCoreServices","AssetsLibrary","CoreMotion","ImageIO","CoreData","CoreLocation","Security","SystemConfiguration","CoreTelephony","CFNetwork","CoreGraphics","UIKit","Foundation"

  s.libraries = "z","stdc++","sqlite3.0"




  s.ios.deployment_target = '8.0'




end

