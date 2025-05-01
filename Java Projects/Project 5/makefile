# Derleyici ve bayraklar
JAVAC = javac
JAVA = java
JFLAGS =

# Ana sınıf adı (main method içeren sınıf)
MAIN = Main

# Kaynak ve sınıf dosyaları
SOURCES = Main.java MyMinHeap.java MyPriorityQueue.java MyTask.java MyUser.java
CLASSES = $(SOURCES:.java=.class)

# build: Tüm sınıf dosyalarını oluştur
build: $(CLASSES)

# Tek tek .java dosyalarını derle
%.class: %.java
	$(JAVAC) $(JFLAGS) $<

# run: Derleme yapar ve programı çalıştırır (örneğin: make run ARGS="testinput.txt config.txt")
run: build
	$(JAVA) $(MAIN) $(ARGS)

# clean: Tüm .class dosyalarını siler
clean:
	@rm -f *.class
