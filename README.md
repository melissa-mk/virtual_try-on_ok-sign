# Face Recognition and Hand Gesture Detection Project

This project is a comprehensive system that combines face recognition and hand gesture detection using computer vision techniques. The system is built using Python and leverages various libraries such as OpenCV, Tensorflow, MediaPipe, and SQLite.

## Features

- Capture and store face images for multiple customers in a SQLite database.
- Cluster face images using K-Means clustering and the VGG16 pre-trained model for feature extraction.
- Train an LBPH (Local Binary Patterns Histograms) face recognizer model using the clustered face images.
- Detect faces in real-time video feed using the trained LBPH model.
- Display the recognized customer's name and confidence score.
- Detect the "OK" hand gesture using MediaPipe's hand landmark detection.
- Update the database to mark when a customer has shown the "OK" sign.
- Allow the user to virtually try on sunglasses when their face is recognized.
- Add the selected sunglasses to the user's cart in the database when they make the "OK" sign gesture.

## Notes

- The project is designed to work with a local webcam. If you want to use a different video source, modify the `cv2.VideoCapture` call in `05_make_predictions.py`.
- The database file `customer_faces_data.db` will be created automatically if it doesn't exist.
- The `models` directory should contain the `haarcascade_frontalface_default.xml` file for face detection. You can download it from the OpenCV repository.
- The number of clusters for K-Means clustering can be adjusted in `02_create_clusters.py`.
- The confidence threshold for face recognition can be adjusted in `05_make_predictions.py`.
- You need to uncomment `add_ok_sign_column()` in the `05_make_predictions.py` if you are running it for the first time
- You will need `tensorflow version 2.12.0` and `keras version 2.12.0` with a python version of `3.11.9`

## License

This project is licensed under the [MIT License](LICENSE).
Inspired by Laurent-I's work!
