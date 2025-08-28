# Makefile for Linkedlist Arithmetic Calculator
# Author: Hasan Qarmash

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = -lm

# Target executables
CALCULATOR = calculator
EXPRESSION_EVALUATOR = expression_evaluator

# Source files
CALC_SRC = P1_1210611_HasanQarmash_2.c
EXPR_SRC = main.c

# Default target
all: $(CALCULATOR) $(EXPRESSION_EVALUATOR)

# Build large integer calculator
$(CALCULATOR): $(CALC_SRC)
	@echo "🔨 Building Large Integer Calculator..."
	$(CC) $(CFLAGS) -o $(CALCULATOR) $(CALC_SRC) $(LDFLAGS)
	@echo "✅ Calculator built successfully!"

# Build expression evaluator
$(EXPRESSION_EVALUATOR): $(EXPR_SRC)
	@echo "🔨 Building Expression Evaluator..."
	$(CC) $(CFLAGS) -o $(EXPRESSION_EVALUATOR) $(EXPR_SRC) $(LDFLAGS)
	@echo "✅ Expression Evaluator built successfully!"

# Debug builds
debug: CFLAGS += -g -DDEBUG
debug: $(CALCULATOR) $(EXPRESSION_EVALUATOR)

# Clean build files
clean:
	@echo "🧹 Cleaning build files..."
	rm -f $(CALCULATOR) $(EXPRESSION_EVALUATOR)
	rm -f *.o
	@echo "✅ Clean completed!"

# Install (copy to /usr/local/bin)
install: all
	@echo "📦 Installing executables..."
	sudo cp $(CALCULATOR) /usr/local/bin/
	sudo cp $(EXPRESSION_EVALUATOR) /usr/local/bin/
	@echo "✅ Installation completed!"

# Uninstall
uninstall:
	@echo "🗑️  Uninstalling executables..."
	sudo rm -f /usr/local/bin/$(CALCULATOR)
	sudo rm -f /usr/local/bin/$(EXPRESSION_EVALUATOR)
	@echo "✅ Uninstallation completed!"

# Run tests
test: all
	@echo "🧪 Running tests..."
	@echo "Testing Calculator with sample input..."
	@if [ -f read.txt ]; then ./$(CALCULATOR); else echo "⚠️  read.txt not found"; fi
	@echo "Testing Expression Evaluator with sample input..."
	@if [ -f reader.txt ]; then ./$(EXPRESSION_EVALUATOR); else echo "⚠️  reader.txt not found"; fi

# Show help
help:
	@echo "📚 Available targets:"
	@echo "  all                 - Build both programs (default)"
	@echo "  calculator          - Build large integer calculator only"
	@echo "  expression_evaluator - Build expression evaluator only"
	@echo "  debug               - Build with debug symbols"
	@echo "  clean               - Remove build files"
	@echo "  install             - Install to system (requires sudo)"
	@echo "  uninstall           - Remove from system (requires sudo)"
	@echo "  test                - Run basic tests"
	@echo "  help                - Show this help message"

# Declare phony targets
.PHONY: all clean install uninstall test help debug
