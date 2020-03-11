#!/usr/bin/env python

# WS client example

import asyncio
import websockets

async def hello():
	uri = "ws://192.168.1.10:8765"
	async with websockets.connect(uri) as websocket:
		while True:
			name = input("What's your name? ")

			await websocket.send(name)
			print(f"> {name}")

			greeting = await websocket.recv()
			print(f"< {greeting}")

asyncio.get_event_loop().run_until_complete(hello())

