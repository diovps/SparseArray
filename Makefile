BUILD = ./build
SRC = ./src

all: $(BUILD)/Source

$(BUILD)/Source:
	cd $(SRC); $(MAKE)
clean:
	cd $(SRC); $(MAKE) clean
