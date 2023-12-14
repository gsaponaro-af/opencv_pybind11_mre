import cv2
import example

cap = cv2.VideoCapture("file_example_MP4_480_1_5MG.mp4")
assert cap.isOpened(), "Cannot open video"

example.process_video(cap)

print("End")
