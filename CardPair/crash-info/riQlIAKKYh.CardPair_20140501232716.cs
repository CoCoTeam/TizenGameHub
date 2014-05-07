S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: CardPair
PID: 5370
Date: 2014-05-01 23:27:16(GMT+0900)
Executable File Path: /opt/apps/riQlIAKKYh/bin/CardPair
This process is multi-thread process
pid=5370 tid=5370
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 5370, uid 5000)

Register Information
r0   = 0xbec816c0, r1   = 0x00000001
r2   = 0x00000000, r3   = 0x001c1888
r4   = 0xbec816c0, r5   = 0x00000011
r6   = 0x004ba97c, r7   = 0x00600d38
r8   = 0xb25bae78, r9   = 0x00613300
r10  = 0x00000038, fp   = 0xbec818f8
ip   = 0x003c46a0, sp   = 0xbec816b8
lr   = 0xb4248d7f, pc   = 0xb38953ec
cpsr = 0x60000030

Memory Information
MemTotal:   797320 KB
MemFree:    184444 KB
Buffers:     29492 KB
Cached:     298808 KB
VmPeak:     123632 KB
VmSize:     100696 KB
VmLck:           0 KB
VmHWM:       61160 KB
VmRSS:       60092 KB
VmData:      25656 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       43944 KB
VmPTE:         116 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 0095e000 rw-p [heap]
b2310000 b2312000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b231a000 b232b000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
b2416000 b241b000 r-xp /usr/lib/libhaptic-module.so
b2427000 b242c000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
b2461000 b2464000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b246c000 b246d000 r-xp /usr/lib/libdrm_slp.so.1.0.0
b2475000 b247f000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b24ab000 b24bf000 r-xp /usr/lib/libnetwork.so.0.0.0
b24c8000 b24dc000 r-xp /usr/lib/libwifi-direct.so.0.0
b24e4000 b24ec000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b24ed000 b24f6000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b24fe000 b25c3000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b25d1000 b25eb000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b25f5000 b25fe000 r-xp /usr/lib/evas/modules/engines/software_x11/linux-gnueabi-armv7l-1.7.99/module.so
b2607000 b2647000 r-xp /opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so
b264a000 b2667000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair.exe
b2671000 b26e3000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b26eb000 b2725000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b272e000 b2732000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b273a000 b276b000 r-xp /usr/lib/libpulse.so.0.12.4
b2773000 b27d6000 r-xp /usr/lib/libasound.so.2.0.0
b27e0000 b27e3000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b27eb000 b27ef000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b27f8000 b2815000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b281d000 b282b000 r-xp /usr/lib/libmmfsound.so.0.1.0
b2833000 b28cf000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b28db000 b291c000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b2925000 b292e000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b2936000 b2943000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b294c000 b2952000 r-xp /usr/lib/libUMP.so
b295a000 b295d000 r-xp /usr/lib/libmm_ta.so.0.0.0
b2965000 b2974000 r-xp /usr/lib/libICE.so.6.3.0
b297e000 b2983000 r-xp /usr/lib/libSM.so.6.0.1
b298b000 b298c000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b2994000 b299c000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29a4000 b29ac000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b29b7000 b29ba000 r-xp /usr/lib/libmmfsession.so.0.0.0
b29c2000 b2a06000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a0f000 b2a22000 r-xp /usr/lib/libEGL_platform.so
b2a2b000 b2b02000 r-xp /usr/lib/libMali.so
b2b0d000 b2b13000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b1b000 b2b1c000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b25000 b2b63000 r-xp /usr/lib/libGLESv2.so.2.0
b2b6b000 b2bb6000 r-xp /usr/lib/libtiff.so.5.1.0
b2bc1000 b2bea000 r-xp /usr/lib/libturbojpeg.so
b2c03000 b2c09000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c11000 b2c17000 r-xp /usr/lib/libgif.so.4.1.6
b2c1f000 b2c41000 r-xp /usr/lib/libavutil.so.51.73.101
b2c50000 b2c7e000 r-xp /usr/lib/libswscale.so.2.1.101
b2c87000 b2f7e000 r-xp /usr/lib/libavcodec.so.54.59.100
b32a5000 b32be000 r-xp /usr/lib/libpng12.so.0.50.0
b32c7000 b32cd000 r-xp /usr/lib/libfeedback.so.0.1.4
b32d5000 b32e1000 r-xp /usr/lib/libtts.so
b32e9000 b3300000 r-xp /usr/lib/libEGL.so.1.4
b3309000 b33c0000 r-xp /usr/lib/libcairo.so.2.11200.12
b33ca000 b33e4000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b33ed000 b3ce8000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3d5b000 b3d60000 r-xp /usr/lib/libslp_devman_plugin.so
b3d69000 b3d6c000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3d74000 b3d78000 r-xp /usr/lib/libsysman.so.0.2.0
b3d80000 b3d91000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3d9a000 b3d9c000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3da4000 b3da6000 r-xp /usr/lib/libdeviced.so.0.1.0
b3dae000 b3dc4000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3dcc000 b3dce000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3dd6000 b3dd9000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3de1000 b3de4000 r-xp /usr/lib/libdevice-node.so.0.1
b3dec000 b3df0000 r-xp /usr/lib/libheynoti.so.0.0.2
b3df8000 b3e3d000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e46000 b3e5b000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3e64000 b3e68000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3e70000 b3e75000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3e7d000 b3e7e000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3e87000 b3e8a000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3e92000 b3e95000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3e9e000 b3ea1000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3ea9000 b3eaa000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3eb2000 b3ec0000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3ec9000 b3eeb000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3ef3000 b3ef6000 r-xp /usr/lib/libuuid.so.1.3.0
b3eff000 b3f1d000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f25000 b3f3c000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f45000 b3f46000 r-xp /usr/lib/libpmapi.so.1.2
b3f4e000 b3f56000 r-xp /usr/lib/libminizip.so.1.0.0
b3f5e000 b3f69000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3f71000 b4049000 r-xp /usr/lib/libxml2.so.2.7.8
b4056000 b4074000 r-xp /usr/lib/libpcre.so.0.0.1
b407c000 b407f000 r-xp /usr/lib/libiniparser.so.0
b4088000 b408c000 r-xp /usr/lib/libhaptic.so.0.1
b4094000 b409f000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40ac000 b40b1000 r-xp /usr/lib/libdevman.so.0.1
b40ba000 b40be000 r-xp /usr/lib/libchromium.so.1.0
b40c6000 b40cc000 r-xp /usr/lib/libappsvc.so.0.1.0
b40d4000 b40d5000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b40e5000 b40e7000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair
b40ef000 b40f5000 r-xp /usr/lib/libalarm.so.0.0.0
b40fe000 b4110000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4118000 b4417000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b443e000 b4448000 r-xp /lib/libnss_files-2.13.so
b4451000 b445a000 r-xp /lib/libnss_nis-2.13.so
b4463000 b4474000 r-xp /lib/libnsl-2.13.so
b447f000 b4485000 r-xp /lib/libnss_compat-2.13.so
b448e000 b4497000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b47bf000 b47d0000 r-xp /usr/lib/libcom-core.so.0.0.1
b47d8000 b47da000 r-xp /usr/lib/libdri2.so.0.0.0
b47e2000 b47ea000 r-xp /usr/lib/libdrm.so.2.4.0
b47f2000 b47f6000 r-xp /usr/lib/libtbm.so.1.0.0
b47fe000 b4801000 r-xp /usr/lib/libXv.so.1.0.0
b4809000 b48d4000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b48ea000 b48fa000 r-xp /usr/lib/libnotification.so.0.1.0
b4902000 b4926000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b492f000 b493f000 r-xp /lib/libresolv-2.13.so
b4943000 b4945000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b494d000 b4aa0000 r-xp /usr/lib/libcrypto.so.1.0.0
b4abe000 b4b0a000 r-xp /usr/lib/libssl.so.1.0.0
b4b16000 b4b42000 r-xp /usr/lib/libidn.so.11.5.44
b4b4b000 b4b55000 r-xp /usr/lib/libcares.so.2.0.0
b4b5d000 b4b74000 r-xp /lib/libexpat.so.1.5.2
b4b7e000 b4ba2000 r-xp /usr/lib/libicule.so.48.1
b4bab000 b4bb3000 r-xp /usr/lib/libsf_common.so
b4bbb000 b4c56000 r-xp /usr/lib/libstdc++.so.6.0.14
b4c69000 b4d46000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d51000 b4d76000 r-xp /usr/lib/libexif.so.12.3.3
b4d8a000 b4d94000 r-xp /usr/lib/libethumb.so.1.7.99
b4d9c000 b4de0000 r-xp /usr/lib/libsndfile.so.1.0.25
b4dee000 b4df0000 r-xp /usr/lib/libctxdata.so.0.0.0
b4df8000 b4e06000 r-xp /usr/lib/libremix.so.0.0.0
b4e0e000 b4e0f000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e17000 b4e30000 r-xp /usr/lib/liblua-5.1.so
b4e39000 b4e40000 r-xp /usr/lib/libembryo.so.1.7.99
b4e49000 b4e4c000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e54000 b4e91000 r-xp /usr/lib/libcurl.so.4.3.0
b4e9b000 b4e9f000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4ea8000 b4f12000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f1f000 b4f43000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f4c000 b4fa8000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b4fba000 b4fce000 r-xp /usr/lib/libfribidi.so.0.3.1
b4fd6000 b502b000 r-xp /usr/lib/libfreetype.so.6.8.1
b5036000 b505a000 r-xp /usr/lib/libjpeg.so.8.0.2
b5072000 b5089000 r-xp /lib/libz.so.1.2.5
b5091000 b509e000 r-xp /usr/lib/libsensor.so.1.1.0
b50a9000 b50ab000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50b3000 b50b9000 r-xp /usr/lib/libxdgmime.so.1.1.0
b61d0000 b62b8000 r-xp /usr/lib/libicuuc.so.48.1
b62c5000 b63e5000 r-xp /usr/lib/libicui18n.so.48.1
b63f3000 b63f6000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b63fe000 b6407000 r-xp /usr/lib/libvconf.so.0.2.45
b640f000 b641d000 r-xp /usr/lib/libail.so.0.1.0
b6425000 b643d000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b643e000 b6443000 r-xp /usr/lib/libffi.so.5.0.10
b644b000 b644c000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b6454000 b645e000 r-xp /usr/lib/libXext.so.6.4.0
b6467000 b646a000 r-xp /usr/lib/libXtst.so.6.1.0
b6472000 b6478000 r-xp /usr/lib/libXrender.so.1.3.0
b6480000 b6486000 r-xp /usr/lib/libXrandr.so.2.2.0
b648e000 b648f000 r-xp /usr/lib/libXinerama.so.1.0.0
b6498000 b64a1000 r-xp /usr/lib/libXi.so.6.1.0
b64a9000 b64ac000 r-xp /usr/lib/libXfixes.so.3.1.0
b64b4000 b64b6000 r-xp /usr/lib/libXgesture.so.7.0.0
b64be000 b64c0000 r-xp /usr/lib/libXcomposite.so.1.0.0
b64c8000 b64c9000 r-xp /usr/lib/libXdamage.so.1.1.0
b64d2000 b64d9000 r-xp /usr/lib/libXcursor.so.1.0.2
b64e1000 b64e9000 r-xp /usr/lib/libemotion.so.1.7.99
b64f1000 b650c000 r-xp /usr/lib/libecore_con.so.1.7.99
b6515000 b651a000 r-xp /usr/lib/libecore_imf.so.1.7.99
b6523000 b652b000 r-xp /usr/lib/libethumb_client.so.1.7.99
b6533000 b6535000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b653d000 b6541000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b654a000 b6560000 r-xp /usr/lib/libefreet.so.1.7.99
b656a000 b6573000 r-xp /usr/lib/libedbus.so.1.7.99
b657b000 b6580000 r-xp /usr/lib/libecore_fb.so.1.7.99
b6589000 b65e5000 r-xp /usr/lib/libedje.so.1.7.99
b65ef000 b6606000 r-xp /usr/lib/libecore_input.so.1.7.99
b6621000 b6626000 r-xp /usr/lib/libecore_file.so.1.7.99
b662e000 b664b000 r-xp /usr/lib/libecore_evas.so.1.7.99
b6654000 b6693000 r-xp /usr/lib/libeina.so.1.7.99
b669c000 b674b000 r-xp /usr/lib/libevas.so.1.7.99
b676d000 b6780000 r-xp /usr/lib/libeet.so.1.7.99
b6789000 b67f3000 r-xp /lib/libm-2.13.so
b67ff000 b6806000 r-xp /usr/lib/libutilX.so.1.1.0
b680e000 b6813000 r-xp /usr/lib/libappcore-common.so.1.1
b681b000 b6826000 r-xp /usr/lib/libaul.so.0.1.0
b682f000 b6863000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b686c000 b689c000 r-xp /usr/lib/libecore_x.so.1.7.99
b68a5000 b68ba000 r-xp /usr/lib/libecore.so.1.7.99
b68d1000 b69f1000 r-xp /usr/lib/libelementary.so.1.7.99
b6a04000 b6a07000 r-xp /lib/libattr.so.1.1.0
b6a0f000 b6a11000 r-xp /usr/lib/libXau.so.6.0.0
b6a19000 b6a1f000 r-xp /lib/librt-2.13.so
b6a28000 b6a30000 r-xp /lib/libcrypt-2.13.so
b6a60000 b6a63000 r-xp /lib/libcap.so.2.21
b6a6b000 b6a6d000 r-xp /usr/lib/libiri.so
b6a75000 b6a8a000 r-xp /usr/lib/libxcb.so.1.1.0
b6a92000 b6a9d000 r-xp /lib/libunwind.so.8.0.1
b6acb000 b6be8000 r-xp /lib/libc-2.13.so
b6bf6000 b6bff000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c07000 b6c0a000 r-xp /usr/lib/libsmack.so.1.0.0
b6c12000 b6c3e000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c47000 b6c4b000 r-xp /usr/lib/libbundle.so.0.1.22
b6c53000 b6c55000 r-xp /lib/libdl-2.13.so
b6c5e000 b6d38000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d41000 b6dab000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6db5000 b6dc2000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6dcb000 b6eb1000 r-xp /usr/lib/libX11.so.6.3.0
b6ebc000 b6ed0000 r-xp /lib/libpthread-2.13.so
b6ee0000 b6ee4000 r-xp /usr/lib/libappcore-efl.so.1.1
b6eed000 b6eee000 r-xp /usr/lib/libdlog.so.0.0.0
b6ef6000 b6efa000 r-xp /usr/lib/libsys-assert.so
b6f02000 b6f1f000 r-xp /lib/ld-2.13.so
bec63000 bec84000 rwxp [stack]
End of Maps Information

Callstack Information (PID:5370)
Call Stack Count: 29
 0: (0xb38953ec) [/usr/lib/osp/libosp-uifw.so] + 0x4a83ec
 1: Tizen::Ui::Controls::Label::SetText(Tizen::Base::String const&) + 0x18 (0xb3760115) [/usr/lib/osp/libosp-uifw.so] + 0x373115
 2: FormGameMulti::onMatchMyturn(Tizen::Base::String) + 0x73c (0xb265d558) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x13558
 3: non-virtual thunk to FormGameMulti::onMatchMyturn(Tizen::Base::String) + 0x24 (0xb265d644) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x13644
 4: GHTurnbasedMatchController::ReceiveData(ListenerType::Type, Tizen::Base::String) + 0x1d8 (0xb2625124) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1e124
 5: GHSocket::ReceiveData() + 0x494 (0xb26243d8) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1d3d8
 6: GHSocket::OnSocketReadyToReceive(Tizen::Net::Sockets::Socket&) + 0x58 (0xb2623f1c) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1cf1c
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
