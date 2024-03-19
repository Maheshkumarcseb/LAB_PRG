import matplotlib.pyplot as plt 
countries = ['Brazil', 'Germany', 'Italy', 'Argentina', 'Uruguay', 'France', 'England','Spain'] 
wins = [5, 4, 4, 3, 2, 2, 1, 1] 
colors = ['yellow', 'magenta', 'green', 'blue', 'lightblue', 'blue', 'red', 'cyan'] 
plt.pie(wins, labels=countries, autopct='%1.1f%%', colors=colors, startangle=90, 
explode=[0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2], shadow=True) 
plt.title('FIFA World Cup Wins by Country') 
plt.axis('equal') # Equal aspect ratio ensures that the pie chart is circular. 
plt.show()
