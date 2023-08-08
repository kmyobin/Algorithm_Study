SELECT O.ANIMAL_ID, O.NAME FROM ANIMAL_OUTS AS O 
WHERE O.ANIMAL_ID NOT IN (SELECT I.ANIMAL_ID FROM ANIMAL_INS AS I) 
ORDER BY O.ANIMAL_ID;