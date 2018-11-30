Pod::Spec.new do |s|
  s.platform = :ios
  s.ios.deployment_target = '5.0'
  s.name = 'OpenMtopSDK'
  s.version  = "1.6.1.17-SNAPSHOT"
  s.summary = '淘宝MTOPSDK'
  s.description = 'MTOP SDK for IOS'
  s.homepage = 'http://gitlab.alibaba-inc.com/wireless/mtopsdk'
  s.license = {
    :type => 'Copyright',
    :text => <<-LICENSE
              Alibaba-Inc copyright
    LICENSE
  }
  s.requires_arc = true
  s.authors = {'苍至'=>'silu.msl@taobao.com'}

  s.frameworks = 'UIKit', 'Foundation'

  s.dependency  'UTDID'

#  s.dependency  'UTDID'
#  s.dependency  'SecurityGuardSDK'
#  s.dependency  'SGMain'
#  s.dependency  'SGSecurityBody'
#  s.dependency  'SGNoCaptcha'

  s.source = { :git=>"git@gitlab.alibaba-inc.com:wireless/opensdk.git", :commit=> "d81fd09" }

  #s.exclude_files = exclude_files+networksdk_no_arc_files
  s.source_files = 'MtopSDK/*.{h,m,c,mm}'

end
