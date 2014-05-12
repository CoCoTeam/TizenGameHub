S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: CardPair
PID: 5497
Date: 2014-05-11 13:23:47(GMT+0900)
Executable File Path: /opt/apps/riQlIAKKYh/bin/CardPair
This process is multi-thread process
pid=5497 tid=5497
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 5497, uid 5000)

Register Information
r0   = 0x001c82c8, r1   = 0x00000a6c
r2   = 0xb447c330, r3   = 0xb4489940
r4   = 0xb268a619, r5   = 0xb268a59a
r6   = 0xfffee461, r7   = 0xfffc3b94
r8   = 0x00000002, r9   = 0xb25dc1ec
r10  = 0x001c82c8, fp   = 0xbe830d50
ip   = 0xb448a214, sp   = 0xbe830980
lr   = 0xb429cd89, pc   = 0xb2685818
cpsr = 0x20000010

Memory Information
MemTotal:   797320 KB
MemFree:    308732 KB
Buffers:     53388 KB
Cached:     208240 KB
VmPeak:     110008 KB
VmSize:      90124 KB
VmLck:           0 KB
VmHWM:       42932 KB
VmRSS:       41592 KB
VmData:      15040 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       43956 KB
VmPTE:          96 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00446000 rw-p [heap]
b0e3c000 b0e41000 r-xp /usr/lib/libhaptic-module.so
b2363000 b2374000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
b2462000 b2464000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
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
b2650000 b2692000 r-xp /opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so
b269d000 b26bb000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair.exe
b26c6000 b2738000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b2740000 b277a000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b2783000 b2787000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b278f000 b27c0000 r-xp /usr/lib/libpulse.so.0.12.4
b27c8000 b282b000 r-xp /usr/lib/libasound.so.2.0.0
b2835000 b2838000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2840000 b2844000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b284d000 b286a000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2872000 b2880000 r-xp /usr/lib/libmmfsound.so.0.1.0
b2888000 b2924000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b2930000 b2971000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b297a000 b2983000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b298b000 b2998000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b29a1000 b29a7000 r-xp /usr/lib/libUMP.so
b29af000 b29b2000 r-xp /usr/lib/libmm_ta.so.0.0.0
b29ba000 b29c9000 r-xp /usr/lib/libICE.so.6.3.0
b29d3000 b29d8000 r-xp /usr/lib/libSM.so.6.0.1
b29e0000 b29e1000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b29e9000 b29f1000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29f9000 b2a01000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a0c000 b2a0f000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a17000 b2a5b000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a64000 b2a77000 r-xp /usr/lib/libEGL_platform.so
b2a80000 b2b57000 r-xp /usr/lib/libMali.so
b2b62000 b2b68000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b70000 b2b71000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b7a000 b2bb8000 r-xp /usr/lib/libGLESv2.so.2.0
b2bc0000 b2c0b000 r-xp /usr/lib/libtiff.so.5.1.0
b2c16000 b2c3f000 r-xp /usr/lib/libturbojpeg.so
b2c58000 b2c5e000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c66000 b2c6c000 r-xp /usr/lib/libgif.so.4.1.6
b2c74000 b2c96000 r-xp /usr/lib/libavutil.so.51.73.101
b2ca5000 b2cd3000 r-xp /usr/lib/libswscale.so.2.1.101
b2cdc000 b2fd3000 r-xp /usr/lib/libavcodec.so.54.59.100
b32fa000 b3313000 r-xp /usr/lib/libpng12.so.0.50.0
b331c000 b3322000 r-xp /usr/lib/libfeedback.so.0.1.4
b332a000 b3336000 r-xp /usr/lib/libtts.so
b333e000 b3355000 r-xp /usr/lib/libEGL.so.1.4
b335e000 b3415000 r-xp /usr/lib/libcairo.so.2.11200.12
b341f000 b3439000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3442000 b3d3d000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3db0000 b3db5000 r-xp /usr/lib/libslp_devman_plugin.so
b3dbe000 b3dc1000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3dc9000 b3dcd000 r-xp /usr/lib/libsysman.so.0.2.0
b3dd5000 b3de6000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3def000 b3df1000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3df9000 b3dfb000 r-xp /usr/lib/libdeviced.so.0.1.0
b3e03000 b3e19000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e21000 b3e23000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e2b000 b3e2e000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e36000 b3e39000 r-xp /usr/lib/libdevice-node.so.0.1
b3e41000 b3e45000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e4d000 b3e92000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e9b000 b3eb0000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3eb9000 b3ebd000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3ec5000 b3eca000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3ed2000 b3ed3000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3edc000 b3edf000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3ee7000 b3eea000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3ef3000 b3ef6000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3efe000 b3eff000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3f07000 b3f15000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f1e000 b3f40000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f48000 b3f4b000 r-xp /usr/lib/libuuid.so.1.3.0
b3f54000 b3f72000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f7a000 b3f91000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f9a000 b3f9b000 r-xp /usr/lib/libpmapi.so.1.2
b3fa3000 b3fab000 r-xp /usr/lib/libminizip.so.1.0.0
b3fb3000 b3fbe000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3fc6000 b409e000 r-xp /usr/lib/libxml2.so.2.7.8
b40ab000 b40c9000 r-xp /usr/lib/libpcre.so.0.0.1
b40d1000 b40d4000 r-xp /usr/lib/libiniparser.so.0
b40dd000 b40e1000 r-xp /usr/lib/libhaptic.so.0.1
b40e9000 b40f4000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b4101000 b4106000 r-xp /usr/lib/libdevman.so.0.1
b410f000 b4113000 r-xp /usr/lib/libchromium.so.1.0
b411b000 b4121000 r-xp /usr/lib/libappsvc.so.0.1.0
b4129000 b412a000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b413a000 b413c000 r-xp /opt/usr/apps/riQlIAKKYh/bin/CardPair
b4144000 b414a000 r-xp /usr/lib/libalarm.so.0.0.0
b4153000 b4165000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b416d000 b446c000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b4493000 b449d000 r-xp /lib/libnss_files-2.13.so
b44a6000 b44af000 r-xp /lib/libnss_nis-2.13.so
b44b8000 b44c9000 r-xp /lib/libnsl-2.13.so
b44d4000 b44da000 r-xp /lib/libnss_compat-2.13.so
b44e3000 b44ec000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b4814000 b4825000 r-xp /usr/lib/libcom-core.so.0.0.1
b482d000 b482f000 r-xp /usr/lib/libdri2.so.0.0.0
b4837000 b483f000 r-xp /usr/lib/libdrm.so.2.4.0
b4847000 b484b000 r-xp /usr/lib/libtbm.so.1.0.0
b4853000 b4856000 r-xp /usr/lib/libXv.so.1.0.0
b485e000 b4929000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b493f000 b494f000 r-xp /usr/lib/libnotification.so.0.1.0
b4957000 b497b000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b4984000 b4994000 r-xp /lib/libresolv-2.13.so
b4998000 b499a000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b49a2000 b4af5000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b13000 b4b5f000 r-xp /usr/lib/libssl.so.1.0.0
b4b6b000 b4b97000 r-xp /usr/lib/libidn.so.11.5.44
b4ba0000 b4baa000 r-xp /usr/lib/libcares.so.2.0.0
b4bb2000 b4bc9000 r-xp /lib/libexpat.so.1.5.2
b4bd3000 b4bf7000 r-xp /usr/lib/libicule.so.48.1
b4c00000 b4c08000 r-xp /usr/lib/libsf_common.so
b4c10000 b4cab000 r-xp /usr/lib/libstdc++.so.6.0.14
b4cbe000 b4d9b000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4da6000 b4dcb000 r-xp /usr/lib/libexif.so.12.3.3
b4ddf000 b4de9000 r-xp /usr/lib/libethumb.so.1.7.99
b4df1000 b4e35000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e43000 b4e45000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e4d000 b4e5b000 r-xp /usr/lib/libremix.so.0.0.0
b4e63000 b4e64000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e6c000 b4e85000 r-xp /usr/lib/liblua-5.1.so
b4e8e000 b4e95000 r-xp /usr/lib/libembryo.so.1.7.99
b4e9e000 b4ea1000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4ea9000 b4ee6000 r-xp /usr/lib/libcurl.so.4.3.0
b4ef0000 b4ef4000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4efd000 b4f67000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f74000 b4f98000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4fa1000 b4ffd000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b500f000 b5023000 r-xp /usr/lib/libfribidi.so.0.3.1
b502b000 b5080000 r-xp /usr/lib/libfreetype.so.6.8.1
b508b000 b50af000 r-xp /usr/lib/libjpeg.so.8.0.2
b50c7000 b50de000 r-xp /lib/libz.so.1.2.5
b50e6000 b50f3000 r-xp /usr/lib/libsensor.so.1.1.0
b50fe000 b5100000 r-xp /usr/lib/libapp-checker.so.0.1.0
b5108000 b510e000 r-xp /usr/lib/libxdgmime.so.1.1.0
b6225000 b630d000 r-xp /usr/lib/libicuuc.so.48.1
b631a000 b643a000 r-xp /usr/lib/libicui18n.so.48.1
b6448000 b644b000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b6453000 b645c000 r-xp /usr/lib/libvconf.so.0.2.45
b6464000 b6472000 r-xp /usr/lib/libail.so.0.1.0
b647a000 b6492000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b6493000 b6498000 r-xp /usr/lib/libffi.so.5.0.10
b64a0000 b64a1000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b64a9000 b64b3000 r-xp /usr/lib/libXext.so.6.4.0
b64bc000 b64bf000 r-xp /usr/lib/libXtst.so.6.1.0
b64c7000 b64cd000 r-xp /usr/lib/libXrender.so.1.3.0
b64d5000 b64db000 r-xp /usr/lib/libXrandr.so.2.2.0
b64e3000 b64e4000 r-xp /usr/lib/libXinerama.so.1.0.0
b64ed000 b64f6000 r-xp /usr/lib/libXi.so.6.1.0
b64fe000 b6501000 r-xp /usr/lib/libXfixes.so.3.1.0
b6509000 b650b000 r-xp /usr/lib/libXgesture.so.7.0.0
b6513000 b6515000 r-xp /usr/lib/libXcomposite.so.1.0.0
b651d000 b651e000 r-xp /usr/lib/libXdamage.so.1.1.0
b6527000 b652e000 r-xp /usr/lib/libXcursor.so.1.0.2
b6536000 b653e000 r-xp /usr/lib/libemotion.so.1.7.99
b6546000 b6561000 r-xp /usr/lib/libecore_con.so.1.7.99
b656a000 b656f000 r-xp /usr/lib/libecore_imf.so.1.7.99
b6578000 b6580000 r-xp /usr/lib/libethumb_client.so.1.7.99
b6588000 b658a000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6592000 b6596000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b659f000 b65b5000 r-xp /usr/lib/libefreet.so.1.7.99
b65bf000 b65c8000 r-xp /usr/lib/libedbus.so.1.7.99
b65d0000 b65d5000 r-xp /usr/lib/libecore_fb.so.1.7.99
b65de000 b663a000 r-xp /usr/lib/libedje.so.1.7.99
b6644000 b665b000 r-xp /usr/lib/libecore_input.so.1.7.99
b6676000 b667b000 r-xp /usr/lib/libecore_file.so.1.7.99
b6683000 b66a0000 r-xp /usr/lib/libecore_evas.so.1.7.99
b66a9000 b66e8000 r-xp /usr/lib/libeina.so.1.7.99
b66f1000 b67a0000 r-xp /usr/lib/libevas.so.1.7.99
b67c2000 b67d5000 r-xp /usr/lib/libeet.so.1.7.99
b67de000 b6848000 r-xp /lib/libm-2.13.so
b6854000 b685b000 r-xp /usr/lib/libutilX.so.1.1.0
b6863000 b6868000 r-xp /usr/lib/libappcore-common.so.1.1
b6870000 b687b000 r-xp /usr/lib/libaul.so.0.1.0
b6884000 b68b8000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b68c1000 b68f1000 r-xp /usr/lib/libecore_x.so.1.7.99
b68fa000 b690f000 r-xp /usr/lib/libecore.so.1.7.99
b6926000 b6a46000 r-xp /usr/lib/libelementary.so.1.7.99
b6a59000 b6a5c000 r-xp /lib/libattr.so.1.1.0
b6a64000 b6a66000 r-xp /usr/lib/libXau.so.6.0.0
b6a6e000 b6a74000 r-xp /lib/librt-2.13.so
b6a7d000 b6a85000 r-xp /lib/libcrypt-2.13.so
b6ab5000 b6ab8000 r-xp /lib/libcap.so.2.21
b6ac0000 b6ac2000 r-xp /usr/lib/libiri.so
b6aca000 b6adf000 r-xp /usr/lib/libxcb.so.1.1.0
b6ae7000 b6af2000 r-xp /lib/libunwind.so.8.0.1
b6b20000 b6c3d000 r-xp /lib/libc-2.13.so
b6c4b000 b6c54000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c5c000 b6c5f000 r-xp /usr/lib/libsmack.so.1.0.0
b6c67000 b6c93000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c9c000 b6ca0000 r-xp /usr/lib/libbundle.so.0.1.22
b6ca8000 b6caa000 r-xp /lib/libdl-2.13.so
b6cb3000 b6d8d000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d96000 b6e00000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6e0a000 b6e17000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e20000 b6f06000 r-xp /usr/lib/libX11.so.6.3.0
b6f11000 b6f25000 r-xp /lib/libpthread-2.13.so
b6f35000 b6f39000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f42000 b6f43000 r-xp /usr/lib/libdlog.so.0.0.0
b6f4b000 b6f4f000 r-xp /usr/lib/libsys-assert.so
b6f57000 b6f74000 r-xp /lib/ld-2.13.so
be812000 be833000 rwxp [stack]
End of Maps Information

Callstack Information (PID:5497)
Call Stack Count: 26
 0: GHAttackhelperController::OnTransactionReadyToRead(Tizen::Base::String, Tizen::Base::String, Tizen::Web::Json::IJsonValue*) + 0x4e0 (0xb2685818) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x35818
 1: GHController::OnTransactionReadyToRead(Tizen::Net::Http::HttpSession&, Tizen::Net::Http::HttpTransaction&, int) + 0x30c (0xb266a290) [/opt/usr/apps/riQlIAKKYh/lib/libTizenGameHubLibrary.so] + 0x1a290
 2: (0xb259028f) [/usr/lib/osp/libosp-net.so.1] + 0x4928f
 3: Tizen::Base::Runtime::_Event::ProcessListeners(std::tr1::shared_ptr<Tizen::Base::Runtime::IEventArg>) + 0x2c0 (0xb42c31c5) [/usr/lib/osp/libosp-appfw.so] + 0x1561c5
 4: Tizen::Base::Runtime::_Event::Fire(std::tr1::shared_ptr<Tizen::Base::Runtime::IEventArg>) + 0x36 (0xb42c33fb) [/usr/lib/osp/libosp-appfw.so] + 0x1563fb
 5: Tizen::Base::Runtime::_Event::Fire(Tizen::Base::Runtime::IEventArg&) + 0x84 (0xb42c34ed) [/usr/lib/osp/libosp-appfw.so] + 0x1564ed
 6: (0xb25908ff) [/usr/lib/osp/libosp-net.so.1] + 0x498ff
 7: (0xb258fa1f) [/usr/lib/osp/libosp-net.so.1] + 0x48a1f
 8: Tizen::Net::Http::_HttpTransactionImpl::OnSocketReceivedEvent(_GIOChannel*, GIOCondition, void*) + 0x80 (0xb2595075) [/usr/lib/osp/libosp-net.so.1] + 0x4e075
 9: g_io_unix_dispatch + 0x2a (0xb6d17783) [/usr/lib/libglib-2.0.so.0] + 0x64783
10: g_main_context_dispatch + 0xce (0xb6ceba37) [/usr/lib/libglib-2.0.so.0] + 0x38a37
11: _ecore_glib_select + 0x3ae (0xb6909337) [/usr/lib/libecore.so.1] + 0xf337
12: _ecore_main_select + 0x294 (0xb69048b9) [/usr/lib/libecore.so.1] + 0xa8b9
13: _ecore_main_loop_iterate_internal + 0x2de (0xb69052f3) [/usr/lib/libecore.so.1] + 0xb2f3
14: ecore_main_loop_begin + 0x30 (0xb69055cd) [/usr/lib/libecore.so.1] + 0xb5cd
15: elm_run + 0x6 (0xb69ce19f) [/usr/lib/libelementary.so.1] + 0xa819f
16: appcore_efl_main + 0x2d4 (0xb6f377d5) [/usr/lib/libappcore-efl.so.1] + 0x27d5
17: app_efl_main + 0xc6 (0xb3f0f07f) [/usr/lib/libcapi-appfw-application.so.0] + 0x807f
18: Tizen::App::_AppImpl::Execute(Tizen::App::_IAppImpl*) + 0xe6 (0xb425a8b3) [/usr/lib/osp/libosp-appfw.so] + 0xed8b3
19: Tizen::App::UiApp::Execute(Tizen::App::UiApp* (*)(), Tizen::Base::Collection::IList const*) + 0x64 (0xb3aed231) [/usr/lib/osp/libosp-uifw.so] + 0x6ab231
20: OspMain + 0x1ac (0xb26a8f80) [/opt/apps/riQlIAKKYh/bin/CardPair.exe] + 0xbf80
21: main + 0x194 (0xb413af21) [/opt/apps/riQlIAKKYh/bin/CardPair] + 0xf21
22: __launchpad_main_loop + 0xe54 (0xb259) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xb259
23: main + 0x486 (0xbcb3) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xbcb3
24: __libc_start_main + 0x114 (0xb6b356e8) [/lib/libc.so.6] + 0x156e8
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
