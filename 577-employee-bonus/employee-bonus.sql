select emp.name, bon.bonus
from Employee emp left join Bonus bon on bon.empId = emp.empId
where bon.bonus < 1000 or bon.bonus is NULL;