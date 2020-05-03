import asyncio
import websockets
import pygame
import json

done = False;


pygame.init()
if pygame.joystick.get_init:
    print("Joystick found, deploying diplomatic wizards to establish connection...")
pygame.joystick.Joystick(0).init()

while not done:
    

async def hello():
    uri = "ws://192.168.1.37:8765"
    async with websockets.connect(uri) as websocket:
        while True:
            print("Still alive")
            sleep(0.05)
            for event in pygame.event.get():
                print("Unidentified movement in the facility, Captain!")
                if event.type == pygame.JOYAXISMOTION:
                    print("Motion in sector JOYSTICK confirmed!")
                    json_string = json.dumps(vars(event))
                    print("{}".format(json_string)) 
                if event.type == pygame.JOYHATMOTION:
                    print("Hey! Don't touch my hat. I don't want to talk to you anymore.")
                    asyncio.get_event_loop().loop.close()

asyncio.get_event_loop().run_forever()

#pygame.quit()
