select prs.firstName, prs.lastName, ads.city, ads.state
from Person prs left join Address ads on prs.personId = ads.personId