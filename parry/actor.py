class actor():
    def __init__(self, x, y, width, height):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.x_speed = self.y_speed = 0

    def update(self):
        pass
    
    def get_x(self):
        return self.x 
    
    def get_y(self):
        return self.y 

    def get_center_x(self):
        return (self.x + self.width / 2) 

    def get_center_y(self):
        return (self.y + self.height / 2) 
    
    def get_width(self):
        return self.width 

    def get_height(self):
        return self.height 

    def get_x_speed(self):
        return self.xSpeed 

    def set_x_speed(self, s):
        self.xSpeed = s 
    
    def get_y_speed(self):
        return self.ySpeed 

    def set_y_speed(self, s):
        self.ySpeed = s 