S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: CardPair
PID: 5151
Date: 2014-05-19 20:26:24(GMT+0900)
Executable File Path: /opt/apps/riQlIAKKYh/bin/CardPair
This process is multi-thread process
pid=5151 tid=5151
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 5151, uid 5000)

Register Information
r0   = 0x003a3238, r1   = 0x001540b4
r2   = 0x0000000a, r3   = 0xb4480940
r4   = 0xb26760b1, r5   = 0xb2676032
r6   = 0xfffeb9c1, r7   = 0xfffc3b94
r8   = 0x00000002, r9   = 0xb25921ec
r10  = 0x003a3238, fp   = 0xbefc4d30
ip   = 0xb4cad128, sp   = 0xbefc4bd0
lr   = 0xb6b8452c, pc   = 0xb266cb10
cpsr = 0x28000010

Memory Information
MemTotal:   797320 KB
MemFree:     34840 KB
Buffers:     95100 KB
Cached:     416672 KB
VmPeak:     114556 KB
VmSize:      89328 KB
VmLck:           0 KB
VmHWM:       50788 KB
VmRSS:       41728 KB
VmData:      14952 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       44088 KB
VmPTE:          94 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 008d3000 rw-p [heap]
b241c000 b2421000 r-xp /usr/lib/libhaptic-module.so
b2429000 b242b000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b2460000 b2463000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b246b000 b246c000 r-xp /usr/lib/libdrm_slp.so.1.0.0
b2474000 b247e000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b24aa000 b24be000 r-xp /usr/lib/libnetwork.so.0.0.0
b24c7000 b24db000 r-xp /usr/lib/libwifi-direct.so.0.0
b24e3000 b24eb000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b24ec000 b24f5000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b24fd000 b25c2000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b25d0000 b25ed000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b25f6000 b2610000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b261a000 b2623000 r-xp /usr/lib/evas/modules/engines/software_x11/linux-gnueabi-armv7l-1.7.99/module.so
b262c000 b2680000 r-xp /opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so
b268c000 b26b2000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair.exe
b26bd000 b272f000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b2737000 b2771000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b277a000 b277e000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2786000 b27b7000 r-xp /usr/lib/libpulse.so.0.12.4
b27bf000 b2822000 r-xp /usr/lib/libasound.so.2.0.0
b282c000 b282f000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2837000 b283b000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2844000 b2861000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2869000 b2877000 r-xp /usr/lib/libmmfsound.so.0.1.0
b287f000 b291b000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b2927000 b2968000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b2971000 b297a000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b2982000 b298f000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2998000 b299e000 r-xp /usr/lib/libUMP.so
b29a6000 b29a9000 r-xp /usr/lib/libmm_ta.so.0.0.0
b29b1000 b29c0000 r-xp /usr/lib/libICE.so.6.3.0
b29ca000 b29cf000 r-xp /usr/lib/libSM.so.6.0.1
b29d7000 b29d8000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b29e0000 b29e8000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29f0000 b29f8000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a03000 b2a06000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a0e000 b2a52000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a5b000 b2a6e000 r-xp /usr/lib/libEGL_platform.so
b2a77000 b2b4e000 r-xp /usr/lib/libMali.so
b2b59000 b2b5f000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b67000 b2b68000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b71000 b2baf000 r-xp /usr/lib/libGLESv2.so.2.0
b2bb7000 b2c02000 r-xp /usr/lib/libtiff.so.5.1.0
b2c0d000 b2c36000 r-xp /usr/lib/libturbojpeg.so
b2c4f000 b2c55000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c5d000 b2c63000 r-xp /usr/lib/libgif.so.4.1.6
b2c6b000 b2c8d000 r-xp /usr/lib/libavutil.so.51.73.101
b2c9c000 b2cca000 r-xp /usr/lib/libswscale.so.2.1.101
b2cd3000 b2fca000 r-xp /usr/lib/libavcodec.so.54.59.100
b32f1000 b330a000 r-xp /usr/lib/libpng12.so.0.50.0
b3313000 b3319000 r-xp /usr/lib/libfeedback.so.0.1.4
b3321000 b332d000 r-xp /usr/lib/libtts.so
b3335000 b334c000 r-xp /usr/lib/libEGL.so.1.4
b3355000 b340c000 r-xp /usr/lib/libcairo.so.2.11200.12
b3416000 b3430000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3439000 b3d34000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3da7000 b3dac000 r-xp /usr/lib/libslp_devman_plugin.so
b3db5000 b3db8000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3dc0000 b3dc4000 r-xp /usr/lib/libsysman.so.0.2.0
b3dcc000 b3ddd000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3de6000 b3de8000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3df0000 b3df2000 r-xp /usr/lib/libdeviced.so.0.1.0
b3dfa000 b3e10000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e18000 b3e1a000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e22000 b3e25000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e2d000 b3e30000 r-xp /usr/lib/libdevice-node.so.0.1
b3e38000 b3e3c000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e44000 b3e89000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e92000 b3ea7000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3eb0000 b3eb4000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3ebc000 b3ec1000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3ec9000 b3eca000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3ed3000 b3ed6000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3ede000 b3ee1000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3eea000 b3eed000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3ef5000 b3ef6000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3efe000 b3f0c000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f15000 b3f37000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f3f000 b3f42000 r-xp /usr/lib/libuuid.so.1.3.0
b3f4b000 b3f69000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f71000 b3f88000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f91000 b3f92000 r-xp /usr/lib/libpmapi.so.1.2
b3f9a000 b3fa2000 r-xp /usr/lib/libminizip.so.1.0.0
b3faa000 b3fb5000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3fbd000 b4095000 r-xp /usr/lib/libxml2.so.2.7.8
b40a2000 b40c0000 r-xp /usr/lib/libpcre.so.0.0.1
b40c8000 b40cb000 r-xp /usr/lib/libiniparser.so.0
b40d4000 b40d8000 r-xp /usr/lib/libhaptic.so.0.1
b40e0000 b40eb000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40f8000 b40fd000 r-xp /usr/lib/libdevman.so.0.1
b4106000 b410a000 r-xp /usr/lib/libchromium.so.1.0
b4112000 b4118000 r-xp /usr/lib/libappsvc.so.0.1.0
b4120000 b4121000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b4131000 b4133000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair
b413b000 b4141000 r-xp /usr/lib/libalarm.so.0.0.0
b414a000 b415c000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4164000 b4463000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b448a000 b4494000 r-xp /lib/libnss_files-2.13.so
b449d000 b44a6000 r-xp /lib/libnss_nis-2.13.so
b44af000 b44c0000 r-xp /lib/libnsl-2.13.so
b44cb000 b44d1000 r-xp /lib/libnss_compat-2.13.so
b44da000 b44e3000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b480b000 b481c000 r-xp /usr/lib/libcom-core.so.0.0.1
b4824000 b4826000 r-xp /usr/lib/libdri2.so.0.0.0
b482e000 b4836000 r-xp /usr/lib/libdrm.so.2.4.0
b483e000 b4842000 r-xp /usr/lib/libtbm.so.1.0.0
b484a000 b484d000 r-xp /usr/lib/libXv.so.1.0.0
b4855000 b4920000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b4936000 b4946000 r-xp /usr/lib/libnotification.so.0.1.0
b494e000 b4972000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b497b000 b498b000 r-xp /lib/libresolv-2.13.so
b498f000 b4991000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4999000 b4aec000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b0a000 b4b56000 r-xp /usr/lib/libssl.so.1.0.0
b4b62000 b4b8e000 r-xp /usr/lib/libidn.so.11.5.44
b4b97000 b4ba1000 r-xp /usr/lib/libcares.so.2.0.0
b4ba9000 b4bc0000 r-xp /lib/libexpat.so.1.5.2
b4bca000 b4bee000 r-xp /usr/lib/libicule.so.48.1
b4bf7000 b4bff000 r-xp /usr/lib/libsf_common.so
b4c07000 b4ca2000 r-xp /usr/lib/libstdc++.so.6.0.14
b4cb5000 b4d92000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d9d000 b4dc2000 r-xp /usr/lib/libexif.so.12.3.3
b4dd6000 b4de0000 r-xp /usr/lib/libethumb.so.1.7.99
b4de8000 b4e2c000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e3a000 b4e3c000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e44000 b4e52000 r-xp /usr/lib/libremix.so.0.0.0
b4e5a000 b4e5b000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e63000 b4e7c000 r-xp /usr/lib/liblua-5.1.so
b4e85000 b4e8c000 r-xp /usr/lib/libembryo.so.1.7.99
b4e95000 b4e98000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4ea0000 b4edd000 r-xp /usr/lib/libcurl.so.4.3.0
b4ee7000 b4eeb000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4ef4000 b4f5e000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f6b000 b4f8f000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f98000 b4ff4000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b5006000 b501a000 r-xp /usr/lib/libfribidi.so.0.3.1
b5022000 b5077000 r-xp /usr/lib/libfreetype.so.6.8.1
b5082000 b50a6000 r-xp /usr/lib/libjpeg.so.8.0.2
b50be000 b50d5000 r-xp /lib/libz.so.1.2.5
b50dd000 b50ea000 r-xp /usr/lib/libsensor.so.1.1.0
b50f5000 b50f7000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50ff000 b5105000 r-xp /usr/lib/libxdgmime.so.1.1.0
b621c000 b6304000 r-xp /usr/lib/libicuuc.so.48.1
b6311000 b6431000 r-xp /usr/lib/libicui18n.so.48.1
b643f000 b6442000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b644a000 b6453000 r-xp /usr/lib/libvconf.so.0.2.45
b645b000 b6469000 r-xp /usr/lib/libail.so.0.1.0
b6471000 b6489000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b648a000 b648f000 r-xp /usr/lib/libffi.so.5.0.10
b6497000 b6498000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b64a0000 b64aa000 r-xp /usr/lib/libXext.so.6.4.0
b64b3000 b64b6000 r-xp /usr/lib/libXtst.so.6.1.0
b64be000 b64c4000 r-xp /usr/lib/libXrender.so.1.3.0
b64cc000 b64d2000 r-xp /usr/lib/libXrandr.so.2.2.0
b64da000 b64db000 r-xp /usr/lib/libXinerama.so.1.0.0
b64e4000 b64ed000 r-xp /usr/lib/libXi.so.6.1.0
b64f5000 b64f8000 r-xp /usr/lib/libXfixes.so.3.1.0
b6500000 b6502000 r-xp /usr/lib/libXgesture.so.7.0.0
b650a000 b650c000 r-xp /usr/lib/libXcomposite.so.1.0.0
b6514000 b6515000 r-xp /usr/lib/libXdamage.so.1.1.0
b651e000 b6525000 r-xp /usr/lib/libXcursor.so.1.0.2
b652d000 b6535000 r-xp /usr/lib/libemotion.so.1.7.99
b653d000 b6558000 r-xp /usr/lib/libecore_con.so.1.7.99
b6561000 b6566000 r-xp /usr/lib/libecore_imf.so.1.7.99
b656f000 b6577000 r-xp /usr/lib/libethumb_client.so.1.7.99
b657f000 b6581000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6589000 b658d000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b6596000 b65ac000 r-xp /usr/lib/libefreet.so.1.7.99
b65b6000 b65bf000 r-xp /usr/lib/libedbus.so.1.7.99
b65c7000 b65cc000 r-xp /usr/lib/libecore_fb.so.1.7.99
b65d5000 b6631000 r-xp /usr/lib/libedje.so.1.7.99
b663b000 b6652000 r-xp /usr/lib/libecore_input.so.1.7.99
b666d000 b6672000 r-xp /usr/lib/libecore_file.so.1.7.99
b667a000 b6697000 r-xp /usr/lib/libecore_evas.so.1.7.99
b66a0000 b66df000 r-xp /usr/lib/libeina.so.1.7.99
b66e8000 b6797000 r-xp /usr/lib/libevas.so.1.7.99
b67b9000 b67cc000 r-xp /usr/lib/libeet.so.1.7.99
b67d5000 b683f000 r-xp /lib/libm-2.13.so
b684b000 b6852000 r-xp /usr/lib/libutilX.so.1.1.0
b685a000 b685f000 r-xp /usr/lib/libappcore-common.so.1.1
b6867000 b6872000 r-xp /usr/lib/libaul.so.0.1.0
b687b000 b68af000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b68b8000 b68e8000 r-xp /usr/lib/libecore_x.so.1.7.99
b68f1000 b6906000 r-xp /usr/lib/libecore.so.1.7.99
b691d000 b6a3d000 r-xp /usr/lib/libelementary.so.1.7.99
b6a50000 b6a53000 r-xp /lib/libattr.so.1.1.0
b6a5b000 b6a5d000 r-xp /usr/lib/libXau.so.6.0.0
b6a65000 b6a6b000 r-xp /lib/librt-2.13.so
b6a74000 b6a7c000 r-xp /lib/libcrypt-2.13.so
b6aac000 b6aaf000 r-xp /lib/libcap.so.2.21
b6ab7000 b6ab9000 r-xp /usr/lib/libiri.so
b6ac1000 b6ad6000 r-xp /usr/lib/libxcb.so.1.1.0
b6ade000 b6ae9000 r-xp /lib/libunwind.so.8.0.1
b6b17000 b6c34000 r-xp /lib/libc-2.13.so
b6c42000 b6c4b000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c53000 b6c56000 r-xp /usr/lib/libsmack.so.1.0.0
b6c5e000 b6c8a000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c93000 b6c97000 r-xp /usr/lib/libbundle.so.0.1.22
b6c9f000 b6ca1000 r-xp /lib/libdl-2.13.so
b6caa000 b6d84000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d8d000 b6df7000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6e01000 b6e0e000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e17000 b6efd000 r-xp /usr/lib/libX11.so.6.3.0
b6f08000 b6f1c000 r-xp /lib/libpthread-2.13.so
b6f2c000 b6f30000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f39000 b6f3a000 r-xp /usr/lib/libdlog.so.0.0.0
b6f42000 b6f46000 r-xp /usr/lib/libsys-assert.so
b6f4e000 b6f6b000 r-xp /lib/ld-2.13.so
befa6000 befc7000 rwxp [stack]
End of Maps Information

Callstack Information (PID:5151)
Call Stack Count: 26
 0: GHCloudsaveController::OnTransactionReadyToRead(Tizen::Base::String, Tizen::Base::String, Tizen::Web::Json::IJsonValue*) + 0x428 (0xb266cb10) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x40b10
 1: GHController::OnTransactionReadyToRead(Tizen::Net::Http::HttpSession&, Tizen::Net::Http::HttpTransaction&, int) + 0x3b8 (0xb264a790) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1e790
 2: (0xb254628f) [/usr/lib/osp/libosp-net.so.1] + 0x4928f
 3: Tizen::Base::Runtime::_Event::ProcessListeners(std::tr1::shared_ptr<Tizen::Base::Runtime::IEventArg>) + 0x2c0 (0xb42ba1c5) [/usr/lib/osp/libosp-appfw.so] + 0x1561c5
 4: Tizen::Base::Runtime::_Event::Fire(std::tr1::shared_ptr<Tizen::Base::Runtime::IEventArg>) + 0x36 (0xb42ba3fb) [/usr/lib/osp/libosp-appfw.so] + 0x1563fb
 5: Tizen::Base::Runtime::_Event::Fire(Tizen::Base::Runtime::IEventArg&) + 0x84 (0xb42ba4ed) [/usr/lib/osp/libosp-appfw.so] + 0x1564ed
 6: (0xb25468ff) [/usr/lib/osp/libosp-net.so.1] + 0x498ff
 7: (0xb2545a1f) [/usr/lib/osp/libosp-net.so.1] + 0x48a1f
 8: Tizen::Net::Http::_HttpTransactionImpl::OnSocketReceivedEvent(_GIOChannel*, GIOCondition, void*) + 0x80 (0xb254b075) [/usr/lib/osp/libosp-net.so.1] + 0x4e075
 9: g_io_unix_dispatch + 0x2a (0xb6d0e783) [/usr/lib/libglib-2.0.so.0] + 0x64783
10: g_main_context_dispatch + 0xce (0xb6ce2a37) [/usr/lib/libglib-2.0.so.0] + 0x38a37
11: _ecore_glib_select + 0x3ae (0xb6900337) [/usr/lib/libecore.so.1] + 0xf337
12: _ecore_main_select + 0x294 (0xb68fb8b9) [/usr/lib/libecore.so.1] + 0xa8b9
13: _ecore_main_loop_iterate_internal + 0x222 (0xb68fc237) [/usr/lib/libecore.so.1] + 0xb237
14: ecore_main_loop_iterate + 0x26 (0xb68fc52b) [/usr/lib/libecore.so.1] + 0xb52b
15: elm_shutdown + 0x2c (0xb69c4ac9) [/usr/lib/libelementary.so.1] + 0xa7ac9
16: appcore_efl_main + 0x31e (0xb6f2e81f) [/usr/lib/libappcore-efl.so.1] + 0x281f
17: app_efl_main + 0xc6 (0xb3f0607f) [/usr/lib/libcapi-appfw-application.so.0] + 0x807f
18: Tizen::App::_AppImpl::Execute(Tizen::App::_IAppImpl*) + 0xe6 (0xb42518b3) [/usr/lib/osp/libosp-appfw.so] + 0xed8b3
19: Tizen::App::UiApp::Execute(Tizen::App::UiApp* (*)(), Tizen::Base::Collection::IList const*) + 0x64 (0xb3ae4231) [/usr/lib/osp/libosp-uifw.so] + 0x6ab231
20: OspMain + 0x1ac (0xb269b6ac) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0xf6ac
21: main + 0x194 (0xb4131f21) [/opt/apps/riQlIAKKYh/bin/CardPair] + 0xf21
22: __launchpad_main_loop + 0xe54 (0xb259) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xb259
23: main + 0x486 (0xbcb3) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xbcb3
24: __libc_start_main + 0x114 (0xb6b2c6e8) [/lib/libc.so.6] + 0x156e8
25: (0xa110) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xa110
End of Call Stack

Package Information
Package Name: riQlIAKKYh.CardPair
Package ID : riQlIAKKYh
Version: 1.0.0
Package Type: tpk
App Name: CardPair
App ID: riQlIAKKYh.CardPair
Type: Application
Categories: (NULL)
