# Simulateur du coeur de réacteur

## Pour faire les tests dans le navigateur

- Ouvrez un terminal et placez vous à la racine du projet
- Démarrez le serveur avec la commande '''dotnet run'''
- Sur le navigateur, lancez l'URI http://localhost/swagger/
- Si vous préférez utiliser Postman, vous pouvez simplement utiliser l'URI http://localhost
- Pour tester avec l'ESP32, vous devez connecter votre ESP32 au réseau local (le même que de l'ordinateur) et modifier l'adresse du service à appeler à partir du client ESP32. Pour trouver l'adresse du service, trouvez l'adresse IP de votre ordinateur avec la commande '''ipconfig''' et remplacez l'adresse du service par l'URI : "http://<adresse IP de votre ordinateur>/coeur-reacteur"