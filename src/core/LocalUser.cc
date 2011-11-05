/*
 *	 TwitCrusader++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader++
 *
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *		Source: https://github.com/KernelMonkey/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "include/LocalUser.h"

namespace TwitCrusader {

LocalUser::LocalUser()
{
	id=new ustring();
	screenName=new ustring();
	token=new ustring();
	secretToken=new ustring();
	consumerKey=new ustring();
	consumerSecretKey=new ustring();
}

LocalUser::~LocalUser()
{

}

void  LocalUser::setId(ustring id)
{
	this->id->append(id);
}

void  LocalUser::setScreenName(ustring secretName)
{
	this->screenName->append(secretName);
}

void  LocalUser::setToken(ustring Token)
{
	this->token->append(Token);
}

void  LocalUser::setSecretToken(ustring secretToken)
{
	this->secretToken->append(secretToken);
}

void  LocalUser::setConsumerKey(ustring consumerKey)
{
	this->consumerKey->append(consumerKey);
}

void  LocalUser::setConsumerSecretKey(ustring secretConsumerKey)
{
	this->consumerSecretKey->assign(secretConsumerKey);
}

ustring LocalUser::getId()
{
	return *id;
}

ustring LocalUser::getScreenName()
{
	return *screenName;
}

ustring LocalUser::getToken()
{
	return *token;
}

ustring LocalUser::getSecretToken()
{
	return *secretToken;
}

ustring LocalUser::getConsumerKey()
{
	return *consumerKey;
}

void LocalUser::writeUserFile(ustring filename)
{
	Document doc;
	xmlpp::Node* rootNode=doc.create_root_node("CONFIG");
	Element *node =rootNode->add_child("USER");
	node->add_child("screen_name")->set_child_text(*screenName);
	node->add_child("id")->set_child_text(*id);
	node->add_child("consumerKey")->set_child_text(*consumerKey);
	node->add_child("consumerSecretKey")->set_child_text(*consumerSecretKey);
	node->add_child("token")->set_child_text(*token);
	node->add_child("secretToken")->set_child_text(*secretToken);

	doc.write_to_file(filename,"ISO-8859-1");

}

ustring LocalUser::getConsumerSecretKey()
{
	return *consumerSecretKey;
}

bool LocalUser::readUserFile(ustring filename)
{

	DomParser parser;

	parser.set_substitute_entities(); //We just want the text to be resolved/unescaped automatically.

	if(Functions::fileExist(filename)){


		parser.parse_file(filename);
		if(parser)
		{
			//Walk the tree:
			const xmlpp::Node* pNode = parser.get_document()->get_root_node(); //deleted by DomParser.
			const Glib::ustring nodename = pNode->get_name();

			xmlpp::Node::NodeList users = pNode->get_children("USER");
			for(xmlpp::Node::NodeList::iterator user = users.begin(); user != users.end(); ++user)
			{

				xmlpp::Node::NodeList values = user.operator *()->get_children();
				for(xmlpp::Node::NodeList::iterator iter = values.begin(); iter != values.end(); ++iter){

					const xmlpp::Element* nodeElement = dynamic_cast<const xmlpp::Element*>(*iter);

					if(nodeElement){

						if(nodeElement->get_name().compare("id")==0){
							id->assign(nodeElement->get_child_text()->get_content());
						}
						else if(nodeElement->get_name().compare("screen_name")==0){
							screenName->assign(nodeElement->get_child_text()->get_content());
						}
						else if(nodeElement->get_name().compare("token")==0){
							token->assign(nodeElement->get_child_text()->get_content());

						}
						else if(nodeElement->get_name().compare("secretToken")==0){
							secretToken->assign(nodeElement->get_child_text()->get_content());

						}
						else if(nodeElement->get_name().compare("consumerKey")==0){
							consumerKey->assign(nodeElement->get_child_text()->get_content());

						}
						else if(nodeElement->get_name().compare("consumerSecretKey")==0){
							consumerSecretKey->assign(nodeElement->get_child_text()->get_content());

						}
					}

				}

			}
			return true;
		}
	}
	return false;
}
void LocalUser::clear(){
	id=new ustring();
	screenName=new ustring();
	token=new ustring();
	secretToken=new ustring();
	consumerKey=new ustring();
	consumerSecretKey=new ustring();
}
}
