import asyncio
from aiortc import RTCPeerConnection, RTCSessionDescription, MediaStreamTrack
from aiortc.contrib.media import MediaRecorder, MediaBlackhole
from flask import Flask, render_template, request, jsonify
import uuid, os
import logging
from av import VideoFrame
import argparse

# relay = MediaRelay()

# add transformation filters on video track
class VideoTransformTrack(MediaStreamTrack):
	kind = "video"
	def __init__(self, track, transform):
		super().__init__()
		self.track = track
		self.transform = transform

	async def recv(self):
		frame = await self.track.recv()

		if self.transform == "<some tranformation>":
			# Example: return the original frame (or apply transformation and return a VideoFrame)
			return frame  # Replace with actual transformation logic returning a VideoFrame
		else:
			return frame


if __name__ == "__main__":
	parser = argparse.ArgumentParser(description="WebRTC+Flask Live Streaming Application")
	parser.add_argument("--host", default="0.0.0.0", help="Host for HTTP server")
	parser.add_argument("--port", type=int, default=8080, help="Port for HTTP server")
	parser.add_argument("--record_to", help="Write received media to a file")
	parser.add_argument("--verbose", "-v", action="count")
	args = parser.parse_args()
	
	if args.verbose:
		logging.basicConfig(level=logging.DEBUG)
	else:
		logging.basicConfig(level=logging.INFO)
	