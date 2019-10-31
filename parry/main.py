import sys, os
cwd = os.getcwd()
sys.path.append(cwd + "/pyglet")

#Import statements
import pyglet
from pyglet.window import key

#Create game window
pacman_window = pyglet.window.Window(800, 800)

def init():
    pass

def update(dt):
    pass

if __name__ == '__main__':
    init()

    pyglet.clock.schedule_interval(update, 1/120.0)

    pyglet.app.run()
