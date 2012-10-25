BUILD = ./build
SRC = ./src
TEST = test

all: $(BUILD)/Source $(BUILD)/Test

$(BUILD)/Source:
	cd $(SRC); $(MAKE)

$(BUILD)/Test:
	cd $(TEST); $(MAKE)	
clean:
	cd $(SRC); $(MAKE) clean
	cd $(TEST); $(MAKE) clean
