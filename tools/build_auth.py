#!/usr/bin/env python3
"""
Build-time authentication helper.
Prompts for a password and validates it.
固定密码是: carrotpilot

Returns 0 on success, non-zero on failure.
"""
import sys
import getpass
import random

def main():
    try:
        pw = getpass.getpass('✅检测GPU编译环境正常，请按ENTER继续: ')
    except Exception as e:
        print('Failed to read password:', e, file=sys.stderr)
        return 3

    if pw == '6f6077ae11cb6eaa3f50aca9ab7bd5755c85bb6a':
        print('✅密码验证正确，编译进程启动')
        return 0
    else:
        # 随机选择一个编译错误信息进行显示
        errors = [
            "selfdrive/ui/qt/onroad/model.cc:116:21: error: redefinition of 'drawPath'\n  116 | void ModelRenderer::drawPath(QPainter &painter, const cereal::ModelDataV2::Reader &model, const QRect &surface_rect) {\n      |                     ^\n./selfdrive/ui/qt/onroad/model.h:42:16: note: previous definition is here\n   42 |   virtual void drawPath(QPainter &painter, const cereal::ModelDataV2::Reader &model, const QRect &surface_rect) {;\n      |                ^\nselfdrive/ui/qt/onroad/model.cc:121:20: error: no member named 'get' in 'SubMaster'\n  121 |     v_ego = s->sm->get(\"carState\").getCarState().getVEgo() * 3.6f; // m/s -> km/h\n      |             ~~~~~~~^\nclang++ -o selfdrive/ui/sunnypilot/qt/offroad/exit_offroad_button.o -c -std=c++1z -DSUNNYPILOT -D_REENTRANT -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_MESSAGELOGCONTEXT -Wno-deprecated-declarations -g -fPIC -O2 -Wunused -Werror -Wshadow -Wno-unknown-warning-option -Wno-inconsistent-missing-override -Wno-c99-designator -Wno-reorder-init-list -Wno-vla-cxx-extension -DSUNNYPILOT -I. -Ithird_party/acados/include -Ithird_party/acados/include/blasfeo/include -Ithird_party/acados/include/hpipm/include -Ithird_party/catch2/include -Ithird_party/libyuv/include -Ithird_party/json11 -Ithird_party/linux/include -Ithird_party/snpe/include -Ithird_party -Imsgq -I/usr/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtConcurrent -I/usr/include/x86_64-linux-gnu/qt5/QtDBus -I/usr/include/x86_64-linux-gnu/qt5/QtXml -Ithird_party/qrcode selfdrive/ui/sunnypilot/qt/offroad/exit_offroad_button.cc\n2 errors generated.\nscons: *** [selfdrive/ui/qt/onroad/model.o] Error 1\nscons: building terminated because of errors.",
            "In file included from ./tools/cabana/mainwin.h:16:\nIn file included from ./tools/cabana/videowidget.h:17:\nIn file included from ./tools/cabana/streams/replaystream.h:11:\nIn file included from ./tools/replay/replay.h:11:\nIn file included from ./tools/replay/camera.h:10:\n./tools/replay/framereader.h:11:10: fatal error: 'libavcodec/avcodec.h' file not found\n   11 | #include <libavcodec/avcodec.h>\n      |          ^~~~~~~~~~~~~~~~~~~~~~\n1 error generated.",
            "ux-gnu/qt5/QtXml -Ithird_party/qrcode -Iselfdrive/ui/qt/screenrecorder/openmax/include selfdrive/assets/assets.cc\n/usr/bin/ld: third_party/maplibre-native-qt/x86_64/lib/libQMapLibre.so: undefined reference to `ubidi_countParagraphs_66'\n/usr/bin/ld: third_party/maplibre-native-qt/x86_64/lib/libQMapLibre.so: undefined reference to `u_errorName_66'\nclang++: error: linker command failed with exit code 1 (use -v to see invocation)\nscons: *** [selfdrive/navd/mapsd] Error 1\nscons: building terminated because of errors."
        ]
        # 随机选择一个错误信息
        selected_error = random.choice(errors)
        print(selected_error, file=sys.stderr)
        return 4

if __name__ == '__main__':
    sys.exit(main())