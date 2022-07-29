BUILD_DIR=build
BIN=$(BUILD_DIR)/software_raytrace


all: $(BUILD_DIR)
	meson compile -C $(BUILD_DIR)

$(BUILD_DIR):
	meson setup $(BUILD_DIR)

run: all
	./$(BIN)	

debug: all
	gdb $(BIN)

clean:
	rm -rf $(BUILD_DIR)

edit: all
	neovide src/* lib/* meson.build Makefile
