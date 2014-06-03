S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: CardPair
PID: 2570
Date: 2014-05-20 17:59:45(GMT+0900)
Executable File Path: /opt/apps/riQlIAKKYh/bin/CardPair
This process is multi-thread process
pid=2570 tid=2570
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 2570, uid 5000)

Register Information
r0   = 0xa00009c5, r1   = 0x00000000
r2   = 0x00000002, r3   = 0x005e3018
r4   = 0xb264ccb1, r5   = 0xb26c49f2
r6   = 0xfffeb011, r7   = 0xfffc3b94
r8   = 0x00000002, r9   = 0xb25dd1ec
r10  = 0x002d5464, fp   = 0xbea01508
ip   = 0x0000006b, sp   = 0xbea014c8
lr   = 0xb264f8e1, pc   = 0xb26972c0
cpsr = 0x28000010

Memory Information
MemTotal:   797320 KB
MemFree:    178316 KB
Buffers:     47720 KB
Cached:     325928 KB
VmPeak:     117656 KB
VmSize:      92788 KB
VmLck:           0 KB
VmHWM:       53360 KB
VmRSS:       44084 KB
VmData:      17440 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       44120 KB
VmPTE:          98 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00956000 rw-p [heap]
b20e7000 b20ec000 r-xp /usr/lib/libhaptic-module.so
b2474000 b2476000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b24ab000 b24ae000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b24b6000 b24b7000 r-xp /usr/lib/libdrm_slp.so.1.0.0
b24bf000 b24c9000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b24f5000 b2509000 r-xp /usr/lib/libnetwork.so.0.0.0
b2512000 b2526000 r-xp /usr/lib/libwifi-direct.so.0.0
b252e000 b2536000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b2537000 b2540000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b2548000 b260d000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b261b000 b2638000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b2641000 b265b000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b2665000 b266e000 r-xp /usr/lib/evas/modules/engines/software_x11/linux-gnueabi-armv7l-1.7.99/module.so
b2677000 b26d0000 r-xp /opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so
b26db000 b2704000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair.exe
b2710000 b2782000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b278a000 b27c4000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b27cd000 b27d1000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b27d9000 b280a000 r-xp /usr/lib/libpulse.so.0.12.4
b2812000 b2875000 r-xp /usr/lib/libasound.so.2.0.0
b287f000 b2882000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b288a000 b288e000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2897000 b28b4000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b28bc000 b28ca000 r-xp /usr/lib/libmmfsound.so.0.1.0
b28d2000 b296e000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b297a000 b29bb000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b29c4000 b29cd000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b29d5000 b29e2000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b29eb000 b29f1000 r-xp /usr/lib/libUMP.so
b29f9000 b29fc000 r-xp /usr/lib/libmm_ta.so.0.0.0
b2a04000 b2a13000 r-xp /usr/lib/libICE.so.6.3.0
b2a1d000 b2a22000 r-xp /usr/lib/libSM.so.6.0.1
b2a2a000 b2a2b000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b2a33000 b2a3b000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b2a43000 b2a4b000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a56000 b2a59000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a61000 b2aa5000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2aae000 b2ac1000 r-xp /usr/lib/libEGL_platform.so
b2aca000 b2ba1000 r-xp /usr/lib/libMali.so
b2bac000 b2bb2000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2bba000 b2bbb000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2bc4000 b2c02000 r-xp /usr/lib/libGLESv2.so.2.0
b2c0a000 b2c55000 r-xp /usr/lib/libtiff.so.5.1.0
b2c60000 b2c89000 r-xp /usr/lib/libturbojpeg.so
b2ca2000 b2ca8000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2cb0000 b2cb6000 r-xp /usr/lib/libgif.so.4.1.6
b2cbe000 b2ce0000 r-xp /usr/lib/libavutil.so.51.73.101
b2cef000 b2d1d000 r-xp /usr/lib/libswscale.so.2.1.101
b2d26000 b301d000 r-xp /usr/lib/libavcodec.so.54.59.100
b3344000 b335d000 r-xp /usr/lib/libpng12.so.0.50.0
b3366000 b336c000 r-xp /usr/lib/libfeedback.so.0.1.4
b3374000 b3380000 r-xp /usr/lib/libtts.so
b3388000 b339f000 r-xp /usr/lib/libEGL.so.1.4
b33a8000 b345f000 r-xp /usr/lib/libcairo.so.2.11200.12
b3469000 b3483000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b348c000 b3d87000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3dfa000 b3dff000 r-xp /usr/lib/libslp_devman_plugin.so
b3e08000 b3e0b000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3e13000 b3e17000 r-xp /usr/lib/libsysman.so.0.2.0
b3e1f000 b3e30000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3e39000 b3e3b000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3e43000 b3e45000 r-xp /usr/lib/libdeviced.so.0.1.0
b3e4d000 b3e63000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e6b000 b3e6d000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e75000 b3e78000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e80000 b3e83000 r-xp /usr/lib/libdevice-node.so.0.1
b3e8b000 b3e8f000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e97000 b3edc000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3ee5000 b3efa000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3f03000 b3f07000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3f0f000 b3f14000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3f1c000 b3f1d000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3f26000 b3f29000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3f31000 b3f34000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3f3d000 b3f40000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3f48000 b3f49000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3f51000 b3f5f000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f68000 b3f8a000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f92000 b3f95000 r-xp /usr/lib/libuuid.so.1.3.0
b3f9e000 b3fbc000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3fc4000 b3fdb000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3fe4000 b3fe5000 r-xp /usr/lib/libpmapi.so.1.2
b3fed000 b3ff5000 r-xp /usr/lib/libminizip.so.1.0.0
b3ffd000 b4008000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b4010000 b40e8000 r-xp /usr/lib/libxml2.so.2.7.8
b40f5000 b4113000 r-xp /usr/lib/libpcre.so.0.0.1
b411b000 b411e000 r-xp /usr/lib/libiniparser.so.0
b4127000 b412b000 r-xp /usr/lib/libhaptic.so.0.1
b4133000 b413e000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b414b000 b4150000 r-xp /usr/lib/libdevman.so.0.1
b4159000 b415d000 r-xp /usr/lib/libchromium.so.1.0
b4165000 b416b000 r-xp /usr/lib/libappsvc.so.0.1.0
b4173000 b4174000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b4184000 b4186000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair
b418e000 b4194000 r-xp /usr/lib/libalarm.so.0.0.0
b419d000 b41af000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b41b7000 b44b6000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b44dd000 b44e7000 r-xp /lib/libnss_files-2.13.so
b44f0000 b44f9000 r-xp /lib/libnss_nis-2.13.so
b4502000 b4513000 r-xp /lib/libnsl-2.13.so
b451e000 b4524000 r-xp /lib/libnss_compat-2.13.so
b452d000 b4536000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b485e000 b486f000 r-xp /usr/lib/libcom-core.so.0.0.1
b4877000 b4879000 r-xp /usr/lib/libdri2.so.0.0.0
b4881000 b4889000 r-xp /usr/lib/libdrm.so.2.4.0
b4891000 b4895000 r-xp /usr/lib/libtbm.so.1.0.0
b489d000 b48a0000 r-xp /usr/lib/libXv.so.1.0.0
b48a8000 b4973000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b4989000 b4999000 r-xp /usr/lib/libnotification.so.0.1.0
b49a1000 b49c5000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b49ce000 b49de000 r-xp /lib/libresolv-2.13.so
b49e2000 b49e4000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b49ec000 b4b3f000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b5d000 b4ba9000 r-xp /usr/lib/libssl.so.1.0.0
b4bb5000 b4be1000 r-xp /usr/lib/libidn.so.11.5.44
b4bea000 b4bf4000 r-xp /usr/lib/libcares.so.2.0.0
b4bfc000 b4c13000 r-xp /lib/libexpat.so.1.5.2
b4c1d000 b4c41000 r-xp /usr/lib/libicule.so.48.1
b4c4a000 b4c52000 r-xp /usr/lib/libsf_common.so
b4c5a000 b4cf5000 r-xp /usr/lib/libstdc++.so.6.0.14
b4d08000 b4de5000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4df0000 b4e15000 r-xp /usr/lib/libexif.so.12.3.3
b4e29000 b4e33000 r-xp /usr/lib/libethumb.so.1.7.99
b4e3b000 b4e7f000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e8d000 b4e8f000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e97000 b4ea5000 r-xp /usr/lib/libremix.so.0.0.0
b4ead000 b4eae000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4eb6000 b4ecf000 r-xp /usr/lib/liblua-5.1.so
b4ed8000 b4edf000 r-xp /usr/lib/libembryo.so.1.7.99
b4ee8000 b4eeb000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4ef3000 b4f30000 r-xp /usr/lib/libcurl.so.4.3.0
b4f3a000 b4f3e000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4f47000 b4fb1000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4fbe000 b4fe2000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4feb000 b5047000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b5059000 b506d000 r-xp /usr/lib/libfribidi.so.0.3.1
b5075000 b50ca000 r-xp /usr/lib/libfreetype.so.6.8.1
b50d5000 b50f9000 r-xp /usr/lib/libjpeg.so.8.0.2
b5111000 b5128000 r-xp /lib/libz.so.1.2.5
b5130000 b513d000 r-xp /usr/lib/libsensor.so.1.1.0
b5148000 b514a000 r-xp /usr/lib/libapp-checker.so.0.1.0
b5152000 b5158000 r-xp /usr/lib/libxdgmime.so.1.1.0
b626f000 b6357000 r-xp /usr/lib/libicuuc.so.48.1
b6364000 b6484000 r-xp /usr/lib/libicui18n.so.48.1
b6492000 b6495000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b649d000 b64a6000 r-xp /usr/lib/libvconf.so.0.2.45
b64ae000 b64bc000 r-xp /usr/lib/libail.so.0.1.0
b64c4000 b64dc000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b64dd000 b64e2000 r-xp /usr/lib/libffi.so.5.0.10
b64ea000 b64eb000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b64f3000 b64fd000 r-xp /usr/lib/libXext.so.6.4.0
b6506000 b6509000 r-xp /usr/lib/libXtst.so.6.1.0
b6511000 b6517000 r-xp /usr/lib/libXrender.so.1.3.0
b651f000 b6525000 r-xp /usr/lib/libXrandr.so.2.2.0
b652d000 b652e000 r-xp /usr/lib/libXinerama.so.1.0.0
b6537000 b6540000 r-xp /usr/lib/libXi.so.6.1.0
b6548000 b654b000 r-xp /usr/lib/libXfixes.so.3.1.0
b6553000 b6555000 r-xp /usr/lib/libXgesture.so.7.0.0
b655d000 b655f000 r-xp /usr/lib/libXcomposite.so.1.0.0
b6567000 b6568000 r-xp /usr/lib/libXdamage.so.1.1.0
b6571000 b6578000 r-xp /usr/lib/libXcursor.so.1.0.2
b6580000 b6588000 r-xp /usr/lib/libemotion.so.1.7.99
b6590000 b65ab000 r-xp /usr/lib/libecore_con.so.1.7.99
b65b4000 b65b9000 r-xp /usr/lib/libecore_imf.so.1.7.99
b65c2000 b65ca000 r-xp /usr/lib/libethumb_client.so.1.7.99
b65d2000 b65d4000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b65dc000 b65e0000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b65e9000 b65ff000 r-xp /usr/lib/libefreet.so.1.7.99
b6609000 b6612000 r-xp /usr/lib/libedbus.so.1.7.99
b661a000 b661f000 r-xp /usr/lib/libecore_fb.so.1.7.99
b6628000 b6684000 r-xp /usr/lib/libedje.so.1.7.99
b668e000 b66a5000 r-xp /usr/lib/libecore_input.so.1.7.99
b66c0000 b66c5000 r-xp /usr/lib/libecore_file.so.1.7.99
b66cd000 b66ea000 r-xp /usr/lib/libecore_evas.so.1.7.99
b66f3000 b6732000 r-xp /usr/lib/libeina.so.1.7.99
b673b000 b67ea000 r-xp /usr/lib/libevas.so.1.7.99
b680c000 b681f000 r-xp /usr/lib/libeet.so.1.7.99
b6828000 b6892000 r-xp /lib/libm-2.13.so
b689e000 b68a5000 r-xp /usr/lib/libutilX.so.1.1.0
b68ad000 b68b2000 r-xp /usr/lib/libappcore-common.so.1.1
b68ba000 b68c5000 r-xp /usr/lib/libaul.so.0.1.0
b68ce000 b6902000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b690b000 b693b000 r-xp /usr/lib/libecore_x.so.1.7.99
b6944000 b6959000 r-xp /usr/lib/libecore.so.1.7.99
b6970000 b6a90000 r-xp /usr/lib/libelementary.so.1.7.99
b6aa3000 b6aa6000 r-xp /lib/libattr.so.1.1.0
b6aae000 b6ab0000 r-xp /usr/lib/libXau.so.6.0.0
b6ab8000 b6abe000 r-xp /lib/librt-2.13.so
b6ac7000 b6acf000 r-xp /lib/libcrypt-2.13.so
b6aff000 b6b02000 r-xp /lib/libcap.so.2.21
b6b0a000 b6b0c000 r-xp /usr/lib/libiri.so
b6b14000 b6b29000 r-xp /usr/lib/libxcb.so.1.1.0
b6b31000 b6b3c000 r-xp /lib/libunwind.so.8.0.1
b6b6a000 b6c87000 r-xp /lib/libc-2.13.so
b6c95000 b6c9e000 r-xp /lib/libgcc_s-4.5.3.so.1
b6ca6000 b6ca9000 r-xp /usr/lib/libsmack.so.1.0.0
b6cb1000 b6cdd000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6ce6000 b6cea000 r-xp /usr/lib/libbundle.so.0.1.22
b6cf2000 b6cf4000 r-xp /lib/libdl-2.13.so
b6cfd000 b6dd7000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6de0000 b6e4a000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6e54000 b6e61000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e6a000 b6f50000 r-xp /usr/lib/libX11.so.6.3.0
b6f5b000 b6f6f000 r-xp /lib/libpthread-2.13.so
b6f7f000 b6f83000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f8c000 b6f8d000 r-xp /usr/lib/libdlog.so.0.0.0
b6f95000 b6f99000 r-xp /usr/lib/libsys-assert.so
b6fa1000 b6fbe000 r-xp /lib/ld-2.13.so
be9e3000 bea04000 rwxp [stack]
End of Maps Information

Callstack Information (PID:2570)
Call Stack Count: 27
 0: GHController::getIntByKey(Tizen::Web::Json::JsonObject*, Tizen::Base::String const*) + 0x58 (0xb26972c0) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x202c0
 1: GHLeaderboardController::OnTransactionReadyToRead(Tizen::Base::String, Tizen::Base::String, Tizen::Web::Json::IJsonValue*) + 0x1570 (0xb26a8b68) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x31b68
 2: GHController::OnTransactionReadyToRead(Tizen::Net::Http::HttpSession&, Tizen::Net::Http::HttpTransaction&, int) + 0x364 (0xb2696a80) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1fa80
 3: (0xb259128f) [/usr/lib/osp/libosp-net.so.1] + 0x4928f
 4: Tizen::Base::Runtime::_Event::ProcessListeners(std::tr1::shared_ptr<Tizen::Base::Runtime::IEventArg>) + 0x2c0 (0xb430d1c5) [/usr/lib/osp/libosp-appfw.so] + 0x1561c5
 5: Tizen::Base::Runtime::_Event::Fire(std::tr1::shared_ptr<Tizen::Base::Runtime::IEventArg>) + 0x36 (0xb430d3fb) [/usr/lib/osp/libosp-appfw.so] + 0x1563fb
 6: Tizen::Base::Runtime::_Event::Fire(Tizen::Base::Runtime::IEventArg&) + 0x84 (0xb430d4ed) [/usr/lib/osp/libosp-appfw.so] + 0x1564ed
 7: (0xb25918ff) [/usr/lib/osp/libosp-net.so.1] + 0x498ff
 8: (0xb2590a1f) [/usr/lib/osp/libosp-net.so.1] + 0x48a1f
 9: Tizen::Net::Http::_HttpTransactionImpl::OnSocketReceivedEvent(_GIOChannel*, GIOCondition, void*) + 0x80 (0xb2596075) [/usr/lib/osp/libosp-net.so.1] + 0x4e075
10: g_io_unix_dispatch + 0x2a (0xb6d61783) [/usr/lib/libglib-2.0.so.0] + 0x64783
11: g_main_context_dispatch + 0xce (0xb6d35a37) [/usr/lib/libglib-2.0.so.0] + 0x38a37
12: _ecore_glib_select + 0x3ae (0xb6953337) [/usr/lib/libecore.so.1] + 0xf337
13: _ecore_main_select + 0x294 (0xb694e8b9) [/usr/lib/libecore.so.1] + 0xa8b9
14: _ecore_main_loop_iterate_internal + 0x2de (0xb694f2f3) [/usr/lib/libecore.so.1] + 0xb2f3
15: ecore_main_loop_begin + 0x30 (0xb694f5cd) [/usr/lib/libecore.so.1] + 0xb5cd
16: elm_run + 0x6 (0xb6a1819f) [/usr/lib/libelementary.so.1] + 0xa819f
17: appcore_efl_main + 0x2d4 (0xb6f817d5) [/usr/lib/libappcore-efl.so.1] + 0x27d5
18: app_efl_main + 0xc6 (0xb3f5907f) [/usr/lib/libcapi-appfw-application.so.0] + 0x807f
19: Tizen::App::_AppImpl::Execute(Tizen::App::_IAppImpl*) + 0xe6 (0xb42a48b3) [/usr/lib/osp/libosp-appfw.so] + 0xed8b3
20: Tizen::App::UiApp::Execute(Tizen::App::UiApp* (*)(), Tizen::Base::Collection::IList const*) + 0x64 (0xb3b37231) [/usr/lib/osp/libosp-uifw.so] + 0x6ab231
21: OspMain + 0x1ac (0xb26ebc30) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x10c30
22: main + 0x194 (0xb4184f21) [/opt/apps/riQlIAKKYh/bin/CardPair] + 0xf21
23: __launchpad_main_loop + 0xe54 (0xb259) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xb259
24: main + 0x486 (0xbcb3) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xbcb3
25: __libc_start_main + 0x114 (0xb6b7f6e8) [/lib/libc.so.6] + 0x156e8
26: (0xa110) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xa110
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
