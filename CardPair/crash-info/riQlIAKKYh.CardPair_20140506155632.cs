S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: CardPair
PID: 4441
Date: 2014-05-06 15:56:32(GMT+0900)
Executable File Path: /opt/apps/riQlIAKKYh/bin/CardPair
This process is multi-thread process
pid=4441 tid=4441
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 4441, uid 5000)

Register Information
r0   = 0x00000000, r1   = 0x003e4ad8
r2   = 0x00000000, r3   = 0x00000000
r4   = 0xb2689918, r5   = 0xb2689976
r6   = 0x001bfd20, r7   = 0x0065df78
r8   = 0xb2603e78, r9   = 0x004e88f8
r10  = 0x00000038, fp   = 0xbe9118f8
ip   = 0x00000000, sp   = 0xbe911710
lr   = 0xb4290e5f, pc   = 0xb26a6560
cpsr = 0x60000010

Memory Information
MemTotal:   797320 KB
MemFree:    247996 KB
Buffers:     25324 KB
Cached:     285604 KB
VmPeak:     124136 KB
VmSize:     102016 KB
VmLck:           0 KB
VmHWM:       58808 KB
VmRSS:       57576 KB
VmData:      25944 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       43944 KB
VmPTE:         112 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 009a6000 rw-p [heap]
b228f000 b2291000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b2363000 b2374000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
b245f000 b2464000 r-xp /usr/lib/libhaptic-module.so
b2470000 b2475000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
b24aa000 b24ad000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b24b5000 b24b6000 r-xp /usr/lib/libdrm_slp.so.1.0.0
b24be000 b24c8000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b24f4000 b2508000 r-xp /usr/lib/libnetwork.so.0.0.0
b2511000 b2525000 r-xp /usr/lib/libwifi-direct.so.0.0
b252d000 b2535000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b2536000 b253f000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b2547000 b260c000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b261a000 b2634000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b263e000 b2647000 r-xp /usr/lib/evas/modules/engines/software_x11/linux-gnueabi-armv7l-1.7.99/module.so
b2650000 b2690000 r-xp /opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so
b2693000 b26b0000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair.exe
b26ba000 b272c000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b2734000 b276e000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b2777000 b277b000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2783000 b27b4000 r-xp /usr/lib/libpulse.so.0.12.4
b27bc000 b281f000 r-xp /usr/lib/libasound.so.2.0.0
b2829000 b282c000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2834000 b2838000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2841000 b285e000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2866000 b2874000 r-xp /usr/lib/libmmfsound.so.0.1.0
b287c000 b2918000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b2924000 b2965000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b296e000 b2977000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b297f000 b298c000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2995000 b299b000 r-xp /usr/lib/libUMP.so
b29a3000 b29a6000 r-xp /usr/lib/libmm_ta.so.0.0.0
b29ae000 b29bd000 r-xp /usr/lib/libICE.so.6.3.0
b29c7000 b29cc000 r-xp /usr/lib/libSM.so.6.0.1
b29d4000 b29d5000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b29dd000 b29e5000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29ed000 b29f5000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a00000 b2a03000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a0b000 b2a4f000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a58000 b2a6b000 r-xp /usr/lib/libEGL_platform.so
b2a74000 b2b4b000 r-xp /usr/lib/libMali.so
b2b56000 b2b5c000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b64000 b2b65000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b6e000 b2bac000 r-xp /usr/lib/libGLESv2.so.2.0
b2bb4000 b2bff000 r-xp /usr/lib/libtiff.so.5.1.0
b2c0a000 b2c33000 r-xp /usr/lib/libturbojpeg.so
b2c4c000 b2c52000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c5a000 b2c60000 r-xp /usr/lib/libgif.so.4.1.6
b2c68000 b2c8a000 r-xp /usr/lib/libavutil.so.51.73.101
b2c99000 b2cc7000 r-xp /usr/lib/libswscale.so.2.1.101
b2cd0000 b2fc7000 r-xp /usr/lib/libavcodec.so.54.59.100
b32ee000 b3307000 r-xp /usr/lib/libpng12.so.0.50.0
b3310000 b3316000 r-xp /usr/lib/libfeedback.so.0.1.4
b331e000 b332a000 r-xp /usr/lib/libtts.so
b3332000 b3349000 r-xp /usr/lib/libEGL.so.1.4
b3352000 b3409000 r-xp /usr/lib/libcairo.so.2.11200.12
b3413000 b342d000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3436000 b3d31000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3da4000 b3da9000 r-xp /usr/lib/libslp_devman_plugin.so
b3db2000 b3db5000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3dbd000 b3dc1000 r-xp /usr/lib/libsysman.so.0.2.0
b3dc9000 b3dda000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3de3000 b3de5000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3ded000 b3def000 r-xp /usr/lib/libdeviced.so.0.1.0
b3df7000 b3e0d000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e15000 b3e17000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e1f000 b3e22000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e2a000 b3e2d000 r-xp /usr/lib/libdevice-node.so.0.1
b3e35000 b3e39000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e41000 b3e86000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e8f000 b3ea4000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3ead000 b3eb1000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3eb9000 b3ebe000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3ec6000 b3ec7000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3ed0000 b3ed3000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3edb000 b3ede000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3ee7000 b3eea000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3ef2000 b3ef3000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3efb000 b3f09000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f12000 b3f34000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f3c000 b3f3f000 r-xp /usr/lib/libuuid.so.1.3.0
b3f48000 b3f66000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f6e000 b3f85000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f8e000 b3f8f000 r-xp /usr/lib/libpmapi.so.1.2
b3f97000 b3f9f000 r-xp /usr/lib/libminizip.so.1.0.0
b3fa7000 b3fb2000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3fba000 b4092000 r-xp /usr/lib/libxml2.so.2.7.8
b409f000 b40bd000 r-xp /usr/lib/libpcre.so.0.0.1
b40c5000 b40c8000 r-xp /usr/lib/libiniparser.so.0
b40d1000 b40d5000 r-xp /usr/lib/libhaptic.so.0.1
b40dd000 b40e8000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40f5000 b40fa000 r-xp /usr/lib/libdevman.so.0.1
b4103000 b4107000 r-xp /usr/lib/libchromium.so.1.0
b410f000 b4115000 r-xp /usr/lib/libappsvc.so.0.1.0
b411d000 b411e000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b412e000 b4130000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair
b4138000 b413e000 r-xp /usr/lib/libalarm.so.0.0.0
b4147000 b4159000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4161000 b4460000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b4487000 b4491000 r-xp /lib/libnss_files-2.13.so
b449a000 b44a3000 r-xp /lib/libnss_nis-2.13.so
b44ac000 b44bd000 r-xp /lib/libnsl-2.13.so
b44c8000 b44ce000 r-xp /lib/libnss_compat-2.13.so
b44d7000 b44e0000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b4808000 b4819000 r-xp /usr/lib/libcom-core.so.0.0.1
b4821000 b4823000 r-xp /usr/lib/libdri2.so.0.0.0
b482b000 b4833000 r-xp /usr/lib/libdrm.so.2.4.0
b483b000 b483f000 r-xp /usr/lib/libtbm.so.1.0.0
b4847000 b484a000 r-xp /usr/lib/libXv.so.1.0.0
b4852000 b491d000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b4933000 b4943000 r-xp /usr/lib/libnotification.so.0.1.0
b494b000 b496f000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b4978000 b4988000 r-xp /lib/libresolv-2.13.so
b498c000 b498e000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4996000 b4ae9000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b07000 b4b53000 r-xp /usr/lib/libssl.so.1.0.0
b4b5f000 b4b8b000 r-xp /usr/lib/libidn.so.11.5.44
b4b94000 b4b9e000 r-xp /usr/lib/libcares.so.2.0.0
b4ba6000 b4bbd000 r-xp /lib/libexpat.so.1.5.2
b4bc7000 b4beb000 r-xp /usr/lib/libicule.so.48.1
b4bf4000 b4bfc000 r-xp /usr/lib/libsf_common.so
b4c04000 b4c9f000 r-xp /usr/lib/libstdc++.so.6.0.14
b4cb2000 b4d8f000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d9a000 b4dbf000 r-xp /usr/lib/libexif.so.12.3.3
b4dd3000 b4ddd000 r-xp /usr/lib/libethumb.so.1.7.99
b4de5000 b4e29000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e37000 b4e39000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e41000 b4e4f000 r-xp /usr/lib/libremix.so.0.0.0
b4e57000 b4e58000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e60000 b4e79000 r-xp /usr/lib/liblua-5.1.so
b4e82000 b4e89000 r-xp /usr/lib/libembryo.so.1.7.99
b4e92000 b4e95000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e9d000 b4eda000 r-xp /usr/lib/libcurl.so.4.3.0
b4ee4000 b4ee8000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4ef1000 b4f5b000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f68000 b4f8c000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f95000 b4ff1000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b5003000 b5017000 r-xp /usr/lib/libfribidi.so.0.3.1
b501f000 b5074000 r-xp /usr/lib/libfreetype.so.6.8.1
b507f000 b50a3000 r-xp /usr/lib/libjpeg.so.8.0.2
b50bb000 b50d2000 r-xp /lib/libz.so.1.2.5
b50da000 b50e7000 r-xp /usr/lib/libsensor.so.1.1.0
b50f2000 b50f4000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50fc000 b5102000 r-xp /usr/lib/libxdgmime.so.1.1.0
b6219000 b6301000 r-xp /usr/lib/libicuuc.so.48.1
b630e000 b642e000 r-xp /usr/lib/libicui18n.so.48.1
b643c000 b643f000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b6447000 b6450000 r-xp /usr/lib/libvconf.so.0.2.45
b6458000 b6466000 r-xp /usr/lib/libail.so.0.1.0
b646e000 b6486000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b6487000 b648c000 r-xp /usr/lib/libffi.so.5.0.10
b6494000 b6495000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b649d000 b64a7000 r-xp /usr/lib/libXext.so.6.4.0
b64b0000 b64b3000 r-xp /usr/lib/libXtst.so.6.1.0
b64bb000 b64c1000 r-xp /usr/lib/libXrender.so.1.3.0
b64c9000 b64cf000 r-xp /usr/lib/libXrandr.so.2.2.0
b64d7000 b64d8000 r-xp /usr/lib/libXinerama.so.1.0.0
b64e1000 b64ea000 r-xp /usr/lib/libXi.so.6.1.0
b64f2000 b64f5000 r-xp /usr/lib/libXfixes.so.3.1.0
b64fd000 b64ff000 r-xp /usr/lib/libXgesture.so.7.0.0
b6507000 b6509000 r-xp /usr/lib/libXcomposite.so.1.0.0
b6511000 b6512000 r-xp /usr/lib/libXdamage.so.1.1.0
b651b000 b6522000 r-xp /usr/lib/libXcursor.so.1.0.2
b652a000 b6532000 r-xp /usr/lib/libemotion.so.1.7.99
b653a000 b6555000 r-xp /usr/lib/libecore_con.so.1.7.99
b655e000 b6563000 r-xp /usr/lib/libecore_imf.so.1.7.99
b656c000 b6574000 r-xp /usr/lib/libethumb_client.so.1.7.99
b657c000 b657e000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6586000 b658a000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b6593000 b65a9000 r-xp /usr/lib/libefreet.so.1.7.99
b65b3000 b65bc000 r-xp /usr/lib/libedbus.so.1.7.99
b65c4000 b65c9000 r-xp /usr/lib/libecore_fb.so.1.7.99
b65d2000 b662e000 r-xp /usr/lib/libedje.so.1.7.99
b6638000 b664f000 r-xp /usr/lib/libecore_input.so.1.7.99
b666a000 b666f000 r-xp /usr/lib/libecore_file.so.1.7.99
b6677000 b6694000 r-xp /usr/lib/libecore_evas.so.1.7.99
b669d000 b66dc000 r-xp /usr/lib/libeina.so.1.7.99
b66e5000 b6794000 r-xp /usr/lib/libevas.so.1.7.99
b67b6000 b67c9000 r-xp /usr/lib/libeet.so.1.7.99
b67d2000 b683c000 r-xp /lib/libm-2.13.so
b6848000 b684f000 r-xp /usr/lib/libutilX.so.1.1.0
b6857000 b685c000 r-xp /usr/lib/libappcore-common.so.1.1
b6864000 b686f000 r-xp /usr/lib/libaul.so.0.1.0
b6878000 b68ac000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b68b5000 b68e5000 r-xp /usr/lib/libecore_x.so.1.7.99
b68ee000 b6903000 r-xp /usr/lib/libecore.so.1.7.99
b691a000 b6a3a000 r-xp /usr/lib/libelementary.so.1.7.99
b6a4d000 b6a50000 r-xp /lib/libattr.so.1.1.0
b6a58000 b6a5a000 r-xp /usr/lib/libXau.so.6.0.0
b6a62000 b6a68000 r-xp /lib/librt-2.13.so
b6a71000 b6a79000 r-xp /lib/libcrypt-2.13.so
b6aa9000 b6aac000 r-xp /lib/libcap.so.2.21
b6ab4000 b6ab6000 r-xp /usr/lib/libiri.so
b6abe000 b6ad3000 r-xp /usr/lib/libxcb.so.1.1.0
b6adb000 b6ae6000 r-xp /lib/libunwind.so.8.0.1
b6b14000 b6c31000 r-xp /lib/libc-2.13.so
b6c3f000 b6c48000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c50000 b6c53000 r-xp /usr/lib/libsmack.so.1.0.0
b6c5b000 b6c87000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c90000 b6c94000 r-xp /usr/lib/libbundle.so.0.1.22
b6c9c000 b6c9e000 r-xp /lib/libdl-2.13.so
b6ca7000 b6d81000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d8a000 b6df4000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6dfe000 b6e0b000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e14000 b6efa000 r-xp /usr/lib/libX11.so.6.3.0
b6f05000 b6f19000 r-xp /lib/libpthread-2.13.so
b6f29000 b6f2d000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f36000 b6f37000 r-xp /usr/lib/libdlog.so.0.0.0
b6f3f000 b6f43000 r-xp /usr/lib/libsys-assert.so
b6f4b000 b6f68000 r-xp /lib/ld-2.13.so
be8f3000 be914000 rwxp [stack]
End of Maps Information

Callstack Information (PID:4441)
Call Stack Count: 27
 0: FormGameMulti::onMatchMyturn(Tizen::Base::String) + 0x744 (0xb26a6560) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x13560
 1: non-virtual thunk to FormGameMulti::onMatchMyturn(Tizen::Base::String) + 0x24 (0xb26a666c) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x1366c
 2: GHTurnbasedMatchController::ReceiveData(ListenerType::Type, Tizen::Base::String) + 0x1d8 (0xb266e124) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1e124
 3: GHSocket::ReceiveData() + 0x494 (0xb266d3d8) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1d3d8
 4: GHSocket::OnSocketReadyToReceive(Tizen::Net::Sockets::Socket&) + 0x58 (0xb266cf1c) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1cf1c
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
