import sys, os
#sys.path.append(os.getcwd() + "/../pyglet")

#Import statements
import pyglet
from pyglet.window import key

#Create game window
window = pyglet.window.Window()

def init():
    pass

def update(dt):
    pass

if __name__ == '__main__':
    init()

    pyglet.clock.schedule_interval(update, 1/120.0)

    pyglet.app.run()
