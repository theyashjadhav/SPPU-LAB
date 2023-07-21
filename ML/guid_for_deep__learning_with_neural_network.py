import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.utils import resample
from sklearn.metrics import confusion_matrix, accuracy_score
from keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, Activation, Flatten
from tensorflow.keras.layers import Conv2D, MaxPooling2D
from keras.optimizers import Adam
from keras.utils import to_categorical

# Step 1: Data Loading
# Assuming your data is in a CSV file named 'data.csv'
data = pd.read_csv('data.csv')

# Step 2: Data Exploration
# Get the number of rows and columns
num_rows, num_cols = data.shape

# View the first few rows of the data
print(data.head())

# Check data types, missing values, and summary statistics
print(data.info())
print(data.describe())

# Visualize data distribution and relationships (example for numeric features)
plt.scatter(data['Feature1'], data['Target'])
plt.xlabel('Feature1')
plt.ylabel('Target')
plt.show()

# Step 3: Data Preprocessing
# Drop a particular column (e.g., 'ID') if it's not relevant for the analysis
data = data.drop(columns=['ID'])

# Drop rows based on specific conditions (e.g., remove rows with missing values in the 'Feature2' column)
data = data.dropna(subset=['Feature2'])

# Handling Categorical Variables (if any)
# Example: Using Label Encoding for 'Category' column
label_encoder = LabelEncoder()
data['Category'] = label_encoder.fit_transform(data['Category'])

# Feature Scaling (Standardization)
scaler = StandardScaler()
scaled_data = scaler.fit_transform(data.drop(columns=['Target']))

# Step 4: Handling Imbalanced Classes (if any, applicable for classification problems)
# Assuming the target variable 'Target' has imbalanced classes (0 and 1)
# Upsample the minority class (class 1) to balance the dataset
data_majority = data[data['Target'] == 0]
data_minority = data[data['Target'] == 1]
data_minority_upsampled = resample(data_minority, replace=True, n_samples=len(data_majority), random_state=42)
balanced_data = pd.concat([data_majority, data_minority_upsampled])

# Step 5: Train-Test Split
X = balanced_data.drop('Target', axis=1)
y = balanced_data['Target']

# One-hot encode the target variable 'Target'
y = to_categorical(y)

# Split the data into training and testing sets (80% training, 20% testing)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 6: Building the Neural Network Model
model = Sequential()

model.add(Conv2D(32, (3, 3), padding='same', input_shape=input_shape))
model.add(Activation('relu'))
model.add(Conv2D(32, (3, 3)))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.25))

model.add(Conv2D(64, (3, 3), padding='same'))
model.add(Activation('relu'))
model.add(Conv2D(64, (3, 3)))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.25))

model.add(Flatten())
model.add(Dense(256)) 
model.add(Activation('relu'))
model.add(Dropout(0.5))
model.add(Dense(num_classes))
model.add(Activation('softmax'))

# Compile the model
optimizer = Adam(lr=0.001)
model.compile(optimizer=optimizer, loss='categorical_crossentropy', metrics=['accuracy'])

# Step 7: Training the Model
history = model.fit(X_train, y_train, batch_size=32, epochs=50, validation_split=0.2, verbose=1)

# Step 8: Model Evaluation
# Predict on the test set
y_pred = model.predict(X_test)
y_pred_classes = np.argmax(y_pred, axis=1)
y_test_classes = np.argmax(y_test, axis=1)

# Evaluate the model
accuracy = accuracy_score(y_test_classes, y_pred_classes)
print('Neural Network Accuracy:', accuracy)

# Step 9: Confusion Matrix
conf_matrix = confusion_matrix(y_test_classes, y_pred_classes)
plt.figure(figsize=(6, 6))
sns.heatmap(conf_matrix, annot=True, cmap='Blues', fmt='d')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix for Neural Network')
plt.show()

# Step 10: Plot Training and Validation Loss
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.legend()
plt.title('Training and Validation Loss')
plt.show()

# Step 11: Plot Training and Validation Accuracy
plt.plot(history.history['accuracy'], label='Training Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
plt.xlabel('Epochs')
plt.ylabel('Accuracy')
plt.legend()
plt.title('Training and Validation Accuracy')
plt.show()
