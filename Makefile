build:
	mkdir -p out/
	gcc  -I/usr/include/cairo/ `pkg-config --cflags gtk+-3.0` DrawingWindow.c LineDrawing.c TestDDA.c `pkg-config --libs gtk+-3.0` -o out/dda

clean:
	rm -rf out/*

installDeps:
	sudo apt install libgtk-3-dev libcairo2-dev
	sudo ln -s /usr/include/gtk-3.0/gtk /usr/include/gtk
	sudo ln -s /usr/include/gtk-3.0/gdk /usr/include/gdk
