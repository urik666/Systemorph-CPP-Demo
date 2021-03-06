// ImportEntities.cpp : Defines the entry point for the console application.
//

#include <codecvt>
#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

void getOData();
void postImport();

int main()
{
	//postImport();

	getOData();

	// Wait for pressing Enter to continue
	std::string s;
	std::getline(std::cin, s);
	return 0;
}

void getOData()
{
	http_client client(U("http://localhost:29489"));
	http_request request(methods::GET);
	request.headers().add(L"data-Version", L"{'branch':'Test25'}");
	request.set_request_uri(L"/api/LegalEntities");

	pplx::task<http_response> responses = client.request(request);
	http_response response = responses.get();
	std::wcout << response.extract_json().get() << std::endl;
}

void postImport()
{
	utility::string_t Lreq = L"@@LegalEntity\r\nSystemName,DisplayName,V_ValidityFrom,V_Branch,V_Version\r\nSysName,DispName3,01.01.2008,Test25,1";

	// Create an HTTP request.
	// Encode the URI query since it could contain special characters like spaces.
	http_client client(U("http://localhost:29489"));
	http_request request(methods::POST);
	request.headers().add(L"Content-Type", L"text/csv");
	request.headers().add(L"Content-Length", Lreq.length());
	request.set_request_uri(L"/api/import");
	request.set_body(Lreq);

	pplx::task<http_response> responses = client.request(request);
	http_response response = responses.get();
	std::wcout << response.extract_string().get() << std::endl;
}

