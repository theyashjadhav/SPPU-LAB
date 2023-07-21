import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import mean_squared_error, r2_score, confusion_matrix, accuracy_score
from scipy.stats import zscore
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.utils import resample

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
# Handling missing data with mean imputation
data.fillna(data.mean(), inplace=True)

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

# Outlier Detection and Handling (using Z-score)
z_scores = zscore(data['Feature1'])
outliers_indices_zscore = np.abs(z_scores) > 3
data_without_outliers_zscore = data[~outliers_indices_zscore]

# Outlier Detection and Handling (using Interquartile Range - IQR method)
Q1 = data['Feature1'].quantile(0.25)
Q3 = data['Feature1'].quantile(0.75)
IQR = Q3 - Q1
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR
outliers_indices_iqr = (data['Feature1'] < lower_bound) | (data['Feature1'] > upper_bound)
data_without_outliers_iqr = data[~outliers_indices_iqr]

# Feature Engineering (creating a new feature)
data_without_outliers_iqr['Feature3'] = data_without_outliers_iqr['Feature1'] * data_without_outliers_iqr['Feature2']

# Feature Scaling (Min-Max scaling)
from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler()
scaled_data = scaler.fit_transform(data_without_outliers_iqr)

# Step 4: Train-Test Split
X = data_without_outliers_iqr.drop('Target', axis=1)
y = data_without_outliers_iqr['Target']

# Split the data into training and testing sets (80% training, 20% testing)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 5: Selecting a Model (Linear Regression)
linear_model = LinearRegression()
linear_model.fit(X_train, y_train)
linear_y_pred = linear_model.predict(X_test)

# Evaluate the Linear Regression model
linear_mse = mean_squared_error(y_test, linear_y_pred)
linear_r2 = r2_score(y_test, linear_y_pred)
print('Linear Regression Mean Squared Error:', linear_mse)
print('Linear Regression R-squared:', linear_r2)

# Step 6: Selecting a Model (Logistic Regression)
logistic_model = LogisticRegression()
logistic_model.fit(X_train, y_train)
logistic_y_pred = logistic_model.predict(X_test)

# Evaluate the Logistic Regression model
accuracy = accuracy_score(y_test, logistic_y_pred)
print('Logistic Regression Accuracy:', accuracy)

# Step 7: Selecting a Model (Random Forest)
random_forest_model = RandomForestClassifier()
random_forest_model.fit(X_train, y_train)
rf_y_pred = random_forest_model.predict(X_test)

# Evaluate the Random Forest model
rf_accuracy = accuracy_score(y_test, rf_y_pred)
print('Random Forest Accuracy:', rf_accuracy)

# Step 8: Confusion Matrix for Logistic Regression
conf_matrix = confusion_matrix(y_test, logistic_y_pred)
plt.figure(figsize=(6, 6))
sns.heatmap(conf_matrix, annot=True, cmap='Blues', fmt='d')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix for Logistic Regression')
plt.show()

# Step 9: Confusion Matrix for Random Forest
conf_matrix_rf = confusion_matrix(y_test, rf_y_pred)
plt.figure(figsize=(6, 6))
sns.heatmap(conf_matrix_rf, annot=True, cmap='Greens', fmt='d')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix for Random Forest')
plt.show()
