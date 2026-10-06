# scripts/copy_fw.py
Import("env")
import os, shutil

OUT = os.path.join(".pio", "build", "wokwi")
os.makedirs(OUT, exist_ok=True)

def _copy_firmware(src):
    shutil.copy2(src, os.path.join(OUT, os.path.basename(src)))
    print(f"[wokwi] copied {os.path.basename(src)}")

def _copy_to_wokwi(target, source, env):  # callback signature: (target, source, env)
    _copy_firmware(str(target[0]))

# Wokwi loads this shared output; each exercise build selects its firmware.
env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", _copy_to_wokwi)
env.AddPostAction("$BUILD_DIR/${PROGNAME}.elf", _copy_to_wokwi)

# Also select existing outputs when the chosen environment is already up to date.
for artifact in ("firmware.bin", "firmware.elf"):
    src = os.path.join(str(env.subst("$BUILD_DIR")), artifact)
    if os.path.isfile(src):
        _copy_firmware(src)
