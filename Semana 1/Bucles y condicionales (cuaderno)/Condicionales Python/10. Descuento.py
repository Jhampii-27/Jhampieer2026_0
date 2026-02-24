pre = int(input("Ingrese el precio del producto: \n"))

if pre >= 100:
    des = pre - pre * 0.1;
    print (f"El precio despues del 10 por ciento de descuento es: {des}")
elif 0 < pre < 100:
    print ("No se aplica el descuento.")
else:
    print ("El precio no puede ser menor o igual que cero.")