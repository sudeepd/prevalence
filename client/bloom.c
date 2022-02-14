typedef enum hash_t {
    crc,sha1,sha256,sha512,md5
} hash_t;

typedef struct bloom_t {
    unsigned char *buffer;
    unsigned long size;
} bloom_t;

/**
 * Retunrs the number of bits required for the bloom filter given the number of items and acceptable false rate 
 */
unsigned long get_bloom_size(float p, unsigned long long m) {
    n = ceil(m / (-k / log(1 - exp(log(p) / k))))
    p = pow(1 - exp(-k / (m / n)), k)
    m = ceil((n * log(p)) / log(1 / pow(2, log(2))));
    k = round((m / n) * log(2));    
}

struct bloom_t *create_bloom_filter( hash_t hash_type, int false_percent, unsigned long long n_items) {

}