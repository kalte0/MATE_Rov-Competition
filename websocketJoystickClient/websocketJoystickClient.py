import asyncio 
import websockets
import pygame
import time
import json

pygame.init() #Starts the game, finds the joysticks on the system. Automatically includes pygame.joystick.init()
#pygame.joystick.Joystick #Creates a new Joystick object


#if pygame.joystick.Joystick.get_init():
    #print("Joystick object initialized: {pygame.joystick.Joystick.get_name}")
#pygame.joystick.Joystick(1).init()

#print(pygame.joystick.Joystick(0).get_axis(0)) 

done = False; #for the loop, set to False at the beginning of the 

async def hello():
    uri = "ws://192.168.1.37:8765"
    async with websockets.connect(uri) as websocket:
        #while not done:
            #for event in pygame.event.get():
                #if event.type == pygame.QUIT: #If user clicks close:
                    #done = True #set done flag to True, exiting the While loop at the top. 

        while True:
            joystick = pygame.joystick.Joystick(0) # We're only connecting one joystick, no need to do the scan 
            joystick.init()
            
            numAxes = joystick.get_numaxes()
            print("PLEASE WHAT THE FUCK")
            
            pygame.event.pump()
            
            for i in range(numAxes):
                axis = joystick.get_axis(i)
                #json_string = json.dumps(axis)
                await websocket.send("HELLO?")
                greeting = await websocket.recv()
                print(f"< {greeting}")
                time.sleep(0.05)
            
            time.sleep(0.5)
                    

asyncio.get_event_loop().run_forever()

#pygame.quit() #the loop above will keep looping until you exit out of it. Notice while loop inside def numbers will keep sending data until uesr clicks close, then "numbers" will be considered complete and run this.  
