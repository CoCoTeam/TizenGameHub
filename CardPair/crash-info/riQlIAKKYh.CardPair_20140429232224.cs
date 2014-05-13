S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: CardPair
PID: 17488
Date: 2014-04-29 23:22:24(GMT+0900)
Executable File Path: /opt/apps/riQlIAKKYh/bin/CardPair
This process is multi-thread process
pid=17488 tid=17488
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 17488, uid 5000)

Register Information
r0   = 0x002713f8, r1   = 0x0026cc68
r2   = 0xbe9ec85c, r3   = 0x00000000
r4   = 0xb263d938, r5   = 0xb263d996
r6   = 0x0036b990, r7   = 0x005cf148
r8   = 0xb25b7e78, r9   = 0x0049f090
r10  = 0x00000033, fp   = 0xbe9ec898
ip   = 0x001d0768, sp   = 0xbe9ec7d0
lr   = 0xb4244e9d, pc   = 0xb265834c
cpsr = 0x60000010

Memory Information
MemTotal:   797320 KB
MemFree:     35116 KB
Buffers:     47048 KB
Cached:     432864 KB
VmPeak:     126928 KB
VmSize:     105324 KB
VmLck:           0 KB
VmHWM:       63968 KB
VmRSS:       63968 KB
VmData:      29260 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       43940 KB
VmPTE:         116 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 0095e000 rw-p [heap]
b2243000 b2245000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b2317000 b2328000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
b2413000 b2418000 r-xp /usr/lib/libhaptic-module.so
b2424000 b2429000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
b245e000 b2461000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b2469000 b246a000 r-xp /usr/lib/libdrm_slp.so.1.0.0
b2472000 b247c000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b24a8000 b24bc000 r-xp /usr/lib/libnetwork.so.0.0.0
b24c5000 b24d9000 r-xp /usr/lib/libwifi-direct.so.0.0
b24e1000 b24e9000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b24ea000 b24f3000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b24fb000 b25c0000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b25ce000 b25e8000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b25f2000 b25fb000 r-xp /usr/lib/evas/modules/engines/software_x11/linux-gnueabi-armv7l-1.7.99/module.so
b2604000 b2644000 r-xp /opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so
b2647000 b2663000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair.exe
b266d000 b26df000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b26e7000 b2721000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b272a000 b272e000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2736000 b2767000 r-xp /usr/lib/libpulse.so.0.12.4
b276f000 b27d2000 r-xp /usr/lib/libasound.so.2.0.0
b27dc000 b27df000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b27e7000 b27eb000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b27f4000 b2811000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2819000 b2827000 r-xp /usr/lib/libmmfsound.so.0.1.0
b282f000 b28cb000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b28d7000 b2918000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b2921000 b292a000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b2932000 b293f000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2948000 b294e000 r-xp /usr/lib/libUMP.so
b2956000 b2959000 r-xp /usr/lib/libmm_ta.so.0.0.0
b2961000 b2970000 r-xp /usr/lib/libICE.so.6.3.0
b297a000 b297f000 r-xp /usr/lib/libSM.so.6.0.1
b2987000 b2988000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b2990000 b2998000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29a0000 b29a8000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b29b3000 b29b6000 r-xp /usr/lib/libmmfsession.so.0.0.0
b29be000 b2a02000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a0b000 b2a1e000 r-xp /usr/lib/libEGL_platform.so
b2a27000 b2afe000 r-xp /usr/lib/libMali.so
b2b09000 b2b0f000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b17000 b2b18000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b21000 b2b5f000 r-xp /usr/lib/libGLESv2.so.2.0
b2b67000 b2bb2000 r-xp /usr/lib/libtiff.so.5.1.0
b2bbd000 b2be6000 r-xp /usr/lib/libturbojpeg.so
b2bff000 b2c05000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c0d000 b2c13000 r-xp /usr/lib/libgif.so.4.1.6
b2c1b000 b2c3d000 r-xp /usr/lib/libavutil.so.51.73.101
b2c4c000 b2c7a000 r-xp /usr/lib/libswscale.so.2.1.101
b2c83000 b2f7a000 r-xp /usr/lib/libavcodec.so.54.59.100
b32a1000 b32ba000 r-xp /usr/lib/libpng12.so.0.50.0
b32c3000 b32c9000 r-xp /usr/lib/libfeedback.so.0.1.4
b32d1000 b32dd000 r-xp /usr/lib/libtts.so
b32e5000 b32fc000 r-xp /usr/lib/libEGL.so.1.4
b3305000 b33bc000 r-xp /usr/lib/libcairo.so.2.11200.12
b33c6000 b33e0000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b33e9000 b3ce4000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3d57000 b3d5c000 r-xp /usr/lib/libslp_devman_plugin.so
b3d65000 b3d68000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3d70000 b3d74000 r-xp /usr/lib/libsysman.so.0.2.0
b3d7c000 b3d8d000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3d96000 b3d98000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3da0000 b3da2000 r-xp /usr/lib/libdeviced.so.0.1.0
b3daa000 b3dc0000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3dc8000 b3dca000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3dd2000 b3dd5000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3ddd000 b3de0000 r-xp /usr/lib/libdevice-node.so.0.1
b3de8000 b3dec000 r-xp /usr/lib/libheynoti.so.0.0.2
b3df4000 b3e39000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e42000 b3e57000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3e60000 b3e64000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3e6c000 b3e71000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3e79000 b3e7a000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3e83000 b3e86000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3e8e000 b3e91000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3e9a000 b3e9d000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3ea5000 b3ea6000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3eae000 b3ebc000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3ec5000 b3ee7000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3eef000 b3ef2000 r-xp /usr/lib/libuuid.so.1.3.0
b3efb000 b3f19000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f21000 b3f38000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f41000 b3f42000 r-xp /usr/lib/libpmapi.so.1.2
b3f4a000 b3f52000 r-xp /usr/lib/libminizip.so.1.0.0
b3f5a000 b3f65000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3f6d000 b4045000 r-xp /usr/lib/libxml2.so.2.7.8
b4052000 b4070000 r-xp /usr/lib/libpcre.so.0.0.1
b4078000 b407b000 r-xp /usr/lib/libiniparser.so.0
b4084000 b4088000 r-xp /usr/lib/libhaptic.so.0.1
b4090000 b409b000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40a8000 b40ad000 r-xp /usr/lib/libdevman.so.0.1
b40b6000 b40ba000 r-xp /usr/lib/libchromium.so.1.0
b40c2000 b40c8000 r-xp /usr/lib/libappsvc.so.0.1.0
b40d0000 b40d1000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b40e1000 b40e3000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair
b40eb000 b40f1000 r-xp /usr/lib/libalarm.so.0.0.0
b40fa000 b410c000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4114000 b4413000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b443a000 b4444000 r-xp /lib/libnss_files-2.13.so
b444d000 b4456000 r-xp /lib/libnss_nis-2.13.so
b445f000 b4470000 r-xp /lib/libnsl-2.13.so
b447b000 b4481000 r-xp /lib/libnss_compat-2.13.so
b448a000 b4493000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b47bb000 b47cc000 r-xp /usr/lib/libcom-core.so.0.0.1
b47d4000 b47d6000 r-xp /usr/lib/libdri2.so.0.0.0
b47de000 b47e6000 r-xp /usr/lib/libdrm.so.2.4.0
b47ee000 b47f2000 r-xp /usr/lib/libtbm.so.1.0.0
b47fa000 b47fd000 r-xp /usr/lib/libXv.so.1.0.0
b4805000 b48d0000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b48e6000 b48f6000 r-xp /usr/lib/libnotification.so.0.1.0
b48fe000 b4922000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b492b000 b493b000 r-xp /lib/libresolv-2.13.so
b493f000 b4941000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4949000 b4a9c000 r-xp /usr/lib/libcrypto.so.1.0.0
b4aba000 b4b06000 r-xp /usr/lib/libssl.so.1.0.0
b4b12000 b4b3e000 r-xp /usr/lib/libidn.so.11.5.44
b4b47000 b4b51000 r-xp /usr/lib/libcares.so.2.0.0
b4b59000 b4b70000 r-xp /lib/libexpat.so.1.5.2
b4b7a000 b4b9e000 r-xp /usr/lib/libicule.so.48.1
b4ba7000 b4baf000 r-xp /usr/lib/libsf_common.so
b4bb7000 b4c52000 r-xp /usr/lib/libstdc++.so.6.0.14
b4c65000 b4d42000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d4d000 b4d72000 r-xp /usr/lib/libexif.so.12.3.3
b4d86000 b4d90000 r-xp /usr/lib/libethumb.so.1.7.99
b4d98000 b4ddc000 r-xp /usr/lib/libsndfile.so.1.0.25
b4dea000 b4dec000 r-xp /usr/lib/libctxdata.so.0.0.0
b4df4000 b4e02000 r-xp /usr/lib/libremix.so.0.0.0
b4e0a000 b4e0b000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e13000 b4e2c000 r-xp /usr/lib/liblua-5.1.so
b4e35000 b4e3c000 r-xp /usr/lib/libembryo.so.1.7.99
b4e45000 b4e48000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e50000 b4e8d000 r-xp /usr/lib/libcurl.so.4.3.0
b4e97000 b4e9b000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4ea4000 b4f0e000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f1b000 b4f3f000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f48000 b4fa4000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b4fb6000 b4fca000 r-xp /usr/lib/libfribidi.so.0.3.1
b4fd2000 b5027000 r-xp /usr/lib/libfreetype.so.6.8.1
b5032000 b5056000 r-xp /usr/lib/libjpeg.so.8.0.2
b506e000 b5085000 r-xp /lib/libz.so.1.2.5
b508d000 b509a000 r-xp /usr/lib/libsensor.so.1.1.0
b50a5000 b50a7000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50af000 b50b5000 r-xp /usr/lib/libxdgmime.so.1.1.0
b61cc000 b62b4000 r-xp /usr/lib/libicuuc.so.48.1
b62c1000 b63e1000 r-xp /usr/lib/libicui18n.so.48.1
b63ef000 b63f2000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b63fa000 b6403000 r-xp /usr/lib/libvconf.so.0.2.45
b640b000 b6419000 r-xp /usr/lib/libail.so.0.1.0
b6421000 b6439000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b643a000 b643f000 r-xp /usr/lib/libffi.so.5.0.10
b6447000 b6448000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b6450000 b645a000 r-xp /usr/lib/libXext.so.6.4.0
b6463000 b6466000 r-xp /usr/lib/libXtst.so.6.1.0
b646e000 b6474000 r-xp /usr/lib/libXrender.so.1.3.0
b647c000 b6482000 r-xp /usr/lib/libXrandr.so.2.2.0
b648a000 b648b000 r-xp /usr/lib/libXinerama.so.1.0.0
b6494000 b649d000 r-xp /usr/lib/libXi.so.6.1.0
b64a5000 b64a8000 r-xp /usr/lib/libXfixes.so.3.1.0
b64b0000 b64b2000 r-xp /usr/lib/libXgesture.so.7.0.0
b64ba000 b64bc000 r-xp /usr/lib/libXcomposite.so.1.0.0
b64c4000 b64c5000 r-xp /usr/lib/libXdamage.so.1.1.0
b64ce000 b64d5000 r-xp /usr/lib/libXcursor.so.1.0.2
b64dd000 b64e5000 r-xp /usr/lib/libemotion.so.1.7.99
b64ed000 b6508000 r-xp /usr/lib/libecore_con.so.1.7.99
b6511000 b6516000 r-xp /usr/lib/libecore_imf.so.1.7.99
b651f000 b6527000 r-xp /usr/lib/libethumb_client.so.1.7.99
b652f000 b6531000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6539000 b653d000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b6546000 b655c000 r-xp /usr/lib/libefreet.so.1.7.99
b6566000 b656f000 r-xp /usr/lib/libedbus.so.1.7.99
b6577000 b657c000 r-xp /usr/lib/libecore_fb.so.1.7.99
b6585000 b65e1000 r-xp /usr/lib/libedje.so.1.7.99
b65eb000 b6602000 r-xp /usr/lib/libecore_input.so.1.7.99
b661d000 b6622000 r-xp /usr/lib/libecore_file.so.1.7.99
b662a000 b6647000 r-xp /usr/lib/libecore_evas.so.1.7.99
b6650000 b668f000 r-xp /usr/lib/libeina.so.1.7.99
b6698000 b6747000 r-xp /usr/lib/libevas.so.1.7.99
b6769000 b677c000 r-xp /usr/lib/libeet.so.1.7.99
b6785000 b67ef000 r-xp /lib/libm-2.13.so
b67fb000 b6802000 r-xp /usr/lib/libutilX.so.1.1.0
b680a000 b680f000 r-xp /usr/lib/libappcore-common.so.1.1
b6817000 b6822000 r-xp /usr/lib/libaul.so.0.1.0
b682b000 b685f000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b6868000 b6898000 r-xp /usr/lib/libecore_x.so.1.7.99
b68a1000 b68b6000 r-xp /usr/lib/libecore.so.1.7.99
b68cd000 b69ed000 r-xp /usr/lib/libelementary.so.1.7.99
b6a00000 b6a03000 r-xp /lib/libattr.so.1.1.0
b6a0b000 b6a0d000 r-xp /usr/lib/libXau.so.6.0.0
b6a15000 b6a1b000 r-xp /lib/librt-2.13.so
b6a24000 b6a2c000 r-xp /lib/libcrypt-2.13.so
b6a5c000 b6a5f000 r-xp /lib/libcap.so.2.21
b6a67000 b6a69000 r-xp /usr/lib/libiri.so
b6a71000 b6a86000 r-xp /usr/lib/libxcb.so.1.1.0
b6a8e000 b6a99000 r-xp /lib/libunwind.so.8.0.1
b6ac7000 b6be4000 r-xp /lib/libc-2.13.so
b6bf2000 b6bfb000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c03000 b6c06000 r-xp /usr/lib/libsmack.so.1.0.0
b6c0e000 b6c3a000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c43000 b6c47000 r-xp /usr/lib/libbundle.so.0.1.22
b6c4f000 b6c51000 r-xp /lib/libdl-2.13.so
b6c5a000 b6d34000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d3d000 b6da7000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6db1000 b6dbe000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6dc7000 b6ead000 r-xp /usr/lib/libX11.so.6.3.0
b6eb8000 b6ecc000 r-xp /lib/libpthread-2.13.so
b6edc000 b6ee0000 r-xp /usr/lib/libappcore-efl.so.1.1
b6ee9000 b6eea000 r-xp /usr/lib/libdlog.so.0.0.0
b6ef2000 b6ef6000 r-xp /usr/lib/libsys-assert.so
b6efe000 b6f1b000 r-xp /lib/ld-2.13.so
be9ce000 be9ef000 rwxp [stack]
End of Maps Information

Callstack Information (PID:17488)
Call Stack Count: 28
 0: FormGameMulti::shuffleCard(Tizen::Base::String) + 0xcc (0xb265834c) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x1134c
 1: FormGameMulti::onMatchStart(Tizen::Base::String) + 0x84 (0xb26596a8) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x126a8
 2: non-virtual thunk to FormGameMulti::onMatchStart(Tizen::Base::String) + 0x24 (0xb2659720) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0x12720
 3: GHTurnbasedMatchController::ReceiveData(ListenerType::Type, Tizen::Base::String) + 0x148 (0xb26220b0) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1e0b0
 4: GHSocket::ReceiveData() + 0x494 (0xb26213f4) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1d3f4
 5: GHSocket::OnSocketReadyToReceive(Tizen::Net::Sockets::Socket&) + 0x58 (0xb2620f38) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1cf38
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
