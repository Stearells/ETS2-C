BUILD_DIR = build/

all: m64 m32

m64:
	gcc main.c ../ets2telemetry.c -m64 -o $(BUILD_DIR)main64.exe

m32: 
	gcc main.c ../ets2telemetry.c -m32 -o $(BUILD_DIR)main32.exe

run32:
	$(BUILD_DIR)main32.exe

run64:
	$(BUILD_DIR)main64.exe