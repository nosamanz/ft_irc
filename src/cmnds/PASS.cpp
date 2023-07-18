// /*
// 	IRC (Internet Relay Chat) sunucusunda "PASS" komutu, bir kullanıcının sunucuya bağlanırken kullanıcı adı ve şifresini doğrulamak için kullanılır.
// Bu komut, kullanıcının kimlik doğrulamasını gerçekleştirmek ve sunucuya erişim izni almak için kullanılır.

// 	IRC sunucusuna bağlanmak isteyen bir kullanıcı, sunucuya ilk olarak bağlantı kurar.
// Daha sonra sunucu tarafından beklenen bir "PASS" komutu göndererek kimlik doğrulama işlemini gerçekleştirir. PASS komutu genellikle aşağıdaki formatta kullanılır:

// ```
// ORNEK KULLANIM: PASS your_password
// ```

// 	Burada "your_password", kullanıcının IRC sunucusuna bağlanmak için belirlediği şifresidir.
// Sunucu, bu şifreyi kullanarak kullanıcının kimlik doğrulamasını yapar ve geçerli bir şifre girildiyse bağlantıyı kabul eder.
// Yanlış şifre girilmesi durumunda sunucu, kullanıcıyı reddeder ve bağlantıyı kapatır.

// 	PASS komutu, IRC sunucusuna bağlanmadan önce kullanıcı kimlik doğrulamasını gerçekleştirmek için kullanılır ve sunucu tarafından desteklenmesi gereken bir komuttur.
// Ancak bazı sunucular, şifre gerektirmeyen anonim bağlantılara izin verir ve bu durumda PASS komutu kullanılmaz.
// */

#include "../../inc/Server.hpp"

void Server::pass(Client &client){
	std::cout << "PASS FUNC" << '\n';
	if (this->_passwd == client.c_pass){
		client.status = 1;
	}
	else
		client.status = 0;
}
