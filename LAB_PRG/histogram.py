import matplotlib.pyplot as plt 
import numpy as np 
np.random.seed(42) 
student_scores = np.random.normal(loc=70, scale=15, size=100) 
plt.hist(student_scores, bins=20, color='skyblue', edgecolor='black') 
plt.xlabel('Student Scores') 
plt.ylabel('Frequency') 
plt.title('Distribution of Student Scores') 
plt.show() 
