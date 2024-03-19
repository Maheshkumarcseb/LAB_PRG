import matplotlib.pyplot as plt 
countries = ['Brazil', 'Russia', 'India', 'China', 'South Africa'] 
population = [213993437, 145912025, 1393409038, 1444216107, 61608912] 
per_capita_income = [9600, 11600, 2300, 11000, 6500] 
circle_size = [pop / 1000000 for pop in population] 
colors = np.arange(len(countries)) 
scatter = plt.scatter(population, per_capita_income, s=circle_size, c=colors, cmap='viridis', 
alpha=0.7, label='BRICS Nations') 
for i, country in enumerate(countries): 
    plt.annotate(country, (population[i], per_capita_income[i]), textcoords="offset points", 
xytext=(0,5), ha='center') 
plt.colorbar(scatter, label='Index') 
plt.xlabel('Population') 
plt.ylabel('Per Capita Income (USD)') 
plt.title('Population vs Per Capita Income of BRICS Nations') 
plt.show() 
