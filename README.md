# prevalence
A cloud based secops tool for determining prevalence of a hash in a managed environment

They key goal of the solution is to make it lightning fast to find prevalence of a file , give its hash, in a managed environment. This is one of the key capabilities in a threat hunting exercise. In general, threat hunter will not search a specific known malware file by name or other attributes, and most times, the search is by hash. The solution to search a hash really fast works as below

There are two core components : The client , and the cloud.

## Client

The client side component does the following
1. Create invetory of all files
2. Uses windows ETW, and whenever a file is opened on the system, it calculates the file hash and inserts it into a SQLite on the client.
3. The hash can then be used as input to a bloom filter. Instead of multiple hashes populating the bloom filter, we use multiple prefixed form of the file hash to generate the bits for the bloom filter
4. The bloom filter is then sent up to the cloud. A prevalence lookup is then a bloom filter evaluation in the cloud

## CSP storage
1. Find hash(etag?) of items in a CSP storage ??
2. Use hash to evaluate bloom filter

## Cloud
1. The cloud maintain a key value mapping of a device and its bloom filter
2. The cloud provides an api that evaluates an hash and provides details about the device that match the hash

The key goal is to make prevalence search very fast.

