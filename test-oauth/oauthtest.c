#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oauth.h>

int parse_reply(const char *reply, char **token, char **secret) {
  int rc;
  int ok=1;
  char **rv = NULL;
  rc = oauth_split_url_parameters(reply, &rv);
  qsort(rv, rc, sizeof(char *), oauth_cmpstringp);
  if( rc==2 
      && !strncmp(rv[0],"oauth_token=",11)
      && !strncmp(rv[1],"oauth_token_secret=",18) ) {
    ok=0;
    if (token)  *token =strdup(&(rv[0][12]));
    if (secret) *secret=strdup(&(rv[1][19]));
    printf("key:    '%s'\nsecret: '%s'\n",*token, *secret); // XXX token&secret may be NULL.
  }
  if(rv) free(rv);
  return ok;
}
//pin= 9598723
int main (int argc, char **argv) {
  system("clear");
  const char *request_token_uri = "https://api.twitter.com/oauth/request_token";
  const char *access_token_uri = "http://api.twitter.com/oauth/authorize";
  const char *c_key         = "df4eyJjVngL2HWtaS8GcQ"; //< consumer key
  const char *c_secret      = "svqV9Colm55tJwvh1RCvvIu2ZTBhs7eN9Y084y1qhbU"; //< consumer secret
  char *t_key    = ""; //< token key
  char *t_secret = ""; //< token secret

  char *req_url = NULL;
  char *postarg = NULL;
  char *reply   = NULL;

  printf("Request token..\n");
    req_url = oauth_sign_url2(request_token_uri, NULL, OA_HMAC, NULL, c_key, c_secret, NULL, NULL);
    reply = oauth_http_get(req_url,postarg);
  printf("\n\n"); printf(reply); printf("\n\n\n");
  if (req_url) free(req_url);
  if (postarg) free(postarg);
  if (!reply) return(1);
  if (parse_reply(reply, &t_key, &t_secret)) return(2);
  free(reply);
  
  printf("Access token..\n");

  req_url = oauth_sign_url2(access_token_uri, &postarg, OA_HMAC, NULL, c_key, c_secret, t_key, t_secret);
  reply = oauth_http_post(req_url,postarg);
  printf("\n\n"); printf(reply); printf("\n\n\n");
  if (req_url) free(req_url);
  if (postarg) free(postarg);
  if (!reply) return(3);
  if(t_key) free(t_key);
  if(t_secret) free(t_secret);
  if (parse_reply(reply, &t_key, &t_secret)) return(4);
  free(reply);

  return 0;
}
