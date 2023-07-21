import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

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

# Step 3: Univariate Data Visualization
# Histogram of a numeric feature
plt.figure(figsize=(8, 6))
plt.hist(data['Feature1'], bins=20, color='skyblue', edgecolor='black')
plt.xlabel('Feature1')
plt.ylabel('Frequency')
plt.title('Histogram of Feature1')
plt.show()

# Box plot of a numeric feature
plt.figure(figsize=(8, 6))
sns.boxplot(x=data['Category'], y=data['Feature2'])
plt.xlabel('Category')
plt.ylabel('Feature2')
plt.title('Box Plot of Feature2 by Category')
plt.show()

# Step 4: Bivariate Data Visualization
# Scatter plot of two numeric features
plt.figure(figsize=(8, 6))
plt.scatter(data['Feature1'], data['Feature2'], color='orange')
plt.xlabel('Feature1')
plt.ylabel('Feature2')
plt.title('Scatter Plot of Feature1 vs. Feature2')
plt.show()

# Pairplot for multiple numeric features
sns.pairplot(data[['Feature1', 'Feature2', 'Feature3']], diag_kind='kde')
plt.title('Pairplot of Numeric Features')
plt.show()

# Step 5: Categorical Data Visualization
# Count plot for a categorical feature
plt.figure(figsize=(8, 6))
sns.countplot(x='Category', data=data)
plt.xlabel('Category')
plt.ylabel('Count')
plt.title('Count Plot of Category')
plt.show()

# Bar plot of a categorical feature with numeric aggregation
plt.figure(figsize=(8, 6))
sns.barplot(x='Category', y='Feature2', data=data, estimator=np.mean)
plt.xlabel('Category')
plt.ylabel('Mean Feature2')
plt.title('Bar Plot of Mean Feature2 by Category')
plt.show()

# Step 6: Correlation Heatmap
correlation_matrix = data.corr()
plt.figure(figsize=(10, 8))
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt=".2f")
plt.title('Correlation Heatmap')
plt.show()

# Step 7: Distribution of Categorical Features
# Using a pie chart
plt.figure(figsize=(6, 6))
data['Category'].value_counts().plot.pie(autopct='%1.1f%%', colors=sns.color_palette('pastel'))
plt.title('Distribution of Category')
plt.ylabel('')
plt.show()

# Step 8: Distribution of Numeric Features
# Using KDE (Kernel Density Estimation) plot
plt.figure(figsize=(8, 6))
sns.kdeplot(data['Feature1'], shade=True, color='purple', label='Feature1')
sns.kdeplot(data['Feature2'], shade=True, color='orange', label='Feature2')
plt.xlabel('Value')
plt.ylabel('Density')
plt.title('KDE Plot of Feature1 and Feature2')
plt.legend()
plt.show()
